/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:05:21 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/05 19:26:48 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/execution.h"

void	ft_dup_io(int in, int out)
{
	dup2(in, 0);
	dup2(out, 1);
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

void	execute_non_builtin(t_shell *shell, char *cmd_path)
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
		ft_dup_io(shell->in_fd, shell->out_fd);
		incub_env = incubate_env(shell->env->next->next);
		execve(cmd_path, shell->cmd->cmd_flags, incub_env);
		exit (127);
	}
	waitpid(pid, &i_stat, 0);
	check_exit_stat(shell, i_stat);
}
