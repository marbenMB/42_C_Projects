/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:56:27 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/06 11:49:00 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/execution.h"

void	pipe_p(t_shell *shell)
{
	t_data	*backup;

	backup = shell->data;
	shell->pipe_p = 0;
	while (backup)
	{
		if (backup->token == PIPE)
		{
			shell->pipe_p = 1;
			break ;
		}
		backup = backup->next;
	}
}

int	get_red_fd(t_data *elem)
{
	int		fd;

	fd = 0;
	if (elem->str && elem->token == RIP)
		fd = open(elem->str, O_RDONLY, 0666);
	else if (elem->str && elem->token == ROP)
		fd = open(elem->str, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (elem->str && elem->token == APND)
		fd = open(elem->str, O_WRONLY | O_CREAT | O_APPEND, 0666);
	return (fd);
}

int	analyse_red_io(t_shell *shell, t_data *elem)
{
	int	fd;

	fd = get_red_fd(elem);
	if (fd < 0)
	{
		error_cmd_arg(&shell->env, "Minishell", elem->str, NSFD);
		return (-1);
	}
	else if (fd > 0)
	{
		if (elem->token == RIP)
		{
			if (shell->in_fd > 0)
				close (shell->in_fd);
			shell->in_fd = fd;
		}
		else if (elem->token == ROP || elem->token == APND)
			shell->out_fd = fd;
	}
	return (0);
}

int	analyse_exec_cmd(t_shell *shell, t_data *elem)
{
	char	*cmd_path;
	int		pip_fd[2];

	if (!shell->cmd->cmd_flags[0] || !shell->cmd->cmd_flags[0][0])
	{
		error_cmd_nf(&shell->env, shell->cmd->cmd_flags[0], CNF);
		return (-1);
	}
	if (shell->cmd->cmd_flags[0] && elem->token == CMD)
	{
		pipe(pip_fd);
		cmd_path = get_cmd_path(shell->env, shell->cmd->cmd_flags[0]);
		if (proccess_cmd(shell, shell->cmd->cmd_flags[0], cmd_path, pip_fd))
		{
			close(pip_fd[1]);
			return (-1);
		}
		close(pip_fd[1]);
		shell->in_fd = pip_fd[0];
		free(cmd_path);
		shell->cmd = shell->cmd->next;
	}
	return (0);
}

int	analyse_exec_buffer(t_shell *shell)
{
	shell->in_fd = 0;
	shell->out_fd = 1;
	pipe_p(shell);
	while (shell->data)
	{
		if (analyse_red_io(shell, shell->data) == -1 \
			|| analyse_exec_cmd(shell, shell->data) == -1)
			while (shell->data->next && shell->data->next->token != PIPE)
				shell->data = shell->data->next;
		shell->data = shell->data->next;
	}
	return (0);
}
