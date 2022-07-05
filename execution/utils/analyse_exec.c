/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:56:27 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/05 18:11:14 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/execution.h"

int	analyse_red_io(t_shell *shell, t_data *elem)
{
	int		fd;

	fd = 0;
	if (elem->str && elem->token == RIP)
		fd = open(elem->str, O_RDONLY, 0666);
	else if (elem->str && elem->token == ROP)
		fd = open(elem->str, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (elem->str && elem->token == APND)
		fd =  open(elem->str, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd < 0)
	{
		error_cmd_arg(&shell->env, "Minishell", elem->str, NSFD);
		return (-1);
	}
	else if (fd > 0)
	{
		if (elem->token == RIP)
			shell->in_fd = fd;
		else if (elem->token == ROP || elem->token == APND)
			shell->out_fd = fd;
	}
	// else if (fd > 0)
	// {
	// 	if (elem->token == RIP)
	// 		dup2(fd, 0);
	// 	else if (elem->token == ROP || elem->token == APND)
	// 		dup2(fd, 1);
	// 	// close (fd);
	// }
	return (0);
}

int	analyse_exec_cmd(t_shell *shell, t_data *elem)
{
	char	*cmd_path;
	
	if (elem->token == CMD)
	{
		cmd_path = get_cmd_path(shell->env, shell->cmd->cmd_flags[0]);
		proccess_cmd(shell, shell->cmd->cmd_flags[0], cmd_path);
		shell->cmd = shell->cmd->next;
	}
	return (0);
}

int	analyse_exec_buffer(t_shell *shell)
{
	shell->in_fd = 0;
	shell->out_fd = 1;
	while (shell->data)
	{
		if (analyse_red_io(shell, shell->data) == -1)
			while (shell->data->next && shell->data->next->token != PIPE)
				shell->data = shell->data->next;
		if (analyse_exec_cmd(shell, shell->data) == -1)
		{
			while (shell->data->next && shell->data->next->token != PIPE)
				shell->data = shell->data->next;
		}
			
		shell->data = shell->data->next;
	}
	return (0);
}
