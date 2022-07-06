/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:05:21 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/06 01:04:13 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/execution.h"

void	ft_dup_io(t_shell *shell, int *pip_fd)
{
	if (shell->data->next)
	{
		if (shell->data->prev && (shell->data->prev->token == ROP || shell->data->prev->token == APND))
		{
			dup2(shell->in_fd, 0);
			dup2(shell->out_fd, 1);		
			close(pip_fd[1]);	
		}
		else
		{
			shell->out_fd = pip_fd[1];
			dup2(shell->in_fd, 0);
			dup2(shell->out_fd, 1);	
			close(pip_fd[1]);
		}
	}
	else
	{
		if (shell->data->prev && (shell->data->prev->token == ROP || shell->data->prev->token == APND))
		{
			dup2(shell->in_fd, 0);
			dup2(shell->out_fd, 1);
			close(pip_fd[1]);
		}
		else
		{
			dup2(shell->in_fd, 0);
			close(pip_fd[1]);
		}
	}
}

void	execute_builtin(t_shell *shell, char *cmd)
{
	if (!ft_strcmp(cmd, "cd"))
		ft_cd(shell);
	else if (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "ECHO"))
		ft_echo(shell);
	else if (!ft_strcmp(cmd, "env") || !ft_strcmp(cmd, "ENV"))
		ft_env(shell);
	else if (!ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "PWD"))
		ft_pwd(shell);
	else if (!ft_strcmp(cmd, "export"))
		ft_export(shell);
	else if (!ft_strcmp(cmd, "exit"))
		ft_exit(shell);
	else if (!ft_strcmp(cmd, "unset"))
		ft_unset(shell);
}

void	execute_builtin_child(t_shell *shell, char *cmd, int *pip_fd)
{
	pid_t	pid;
	int		i_stat;
	
	i_stat = 0;
	pid = fork();
	if (pid < 0)
		error_internal_ft(&shell->env, "fork", FIE);
	else if (pid == 0)
	{
		ft_dup_io(shell, pip_fd);
		if (!ft_strcmp(cmd, "cd"))
			ft_cd(shell);
		else if (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "ECHO"))
			ft_echo(shell);
		else if (!ft_strcmp(cmd, "env") || !ft_strcmp(cmd, "ENV"))
			ft_env(shell);
		else if (!ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "PWD"))
			ft_pwd(shell);
		else if (!ft_strcmp(cmd, "export"))
			ft_export(shell);
		else if (!ft_strcmp(cmd, "exit"))
			ft_exit(shell);
		else if (!ft_strcmp(cmd, "unset"))
			ft_unset(shell);
		exit(ft_atoi(shell->env->value));
	}
	waitpid(pid, &i_stat, 0);
	check_exit_stat(shell, i_stat);
}

void	execute_non_builtin(t_shell *shell, char *cmd_path, int *pip_fd)
{
	pid_t	pid;
	int		i_stat;
	char	**incub_env;

	incub_env = NULL;
	i_stat = 0;
	pid = fork();
	if (pid < 0)
		error_internal_ft(&shell->env, "fork", FIE);
	else if (pid == 0)
	{
		ft_dup_io(shell, pip_fd);
		incub_env = incubate_env(shell->env->next->next);
		execve(cmd_path, shell->cmd->cmd_flags, incub_env);
		exit (127);
	}
	if (!shell->data->next)
	{
		waitpid(pid, &i_stat, 0);
		wait(NULL);
	}
	check_exit_stat(shell, i_stat);
}
