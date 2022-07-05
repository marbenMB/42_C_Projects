/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccess_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:45:06 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/05 18:14:45 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/execution.h"

// waitpid(pid, &status, 0);
// WEXITSTATUS(status) ==> EXIT_STATUS ;

int	proccess_cmd(t_shell *shell, char *cmd, char *cmd_path)
{
	int		pid;
	char	*s_stat;
	int		i_stat;
	char	**incub_env;


	incub_env = NULL;
	i_stat = 0;

	if (if_cmd_builtin(cmd) == 1)
	{
		dup2(shell->in_fd, 0);
		dup2(shell->out_fd , 1);
	}
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
	else
	{
		pid = fork();
		if (pid < 0)
			error_internal_ft(&shell->env, "fork", FIE);
		else if (pid == 0)
		{
			dup2(shell->in_fd, 0);
			dup2(shell->out_fd , 1);
			incub_env = incubate_env(shell->env);
			execve(cmd_path, shell->cmd->cmd_flags, incub_env);
			exit (127);
		}
		waitpid(pid, &i_stat, 0);
		if (WIFEXITED(i_stat))
			i_stat = WEXITSTATUS(i_stat);
		else if (WIFSIGNALED(i_stat))
			i_stat += 128;
		s_stat = ft_itoa(i_stat);
		ft_status(&shell->env, s_stat);
		free(s_stat);
		// free_tab(incub_env);
	}
	return (0);
}

int	proccess_buff(t_shell *shell)
{
	t_cmd	*cmd_head;
	t_data	*data_head;

	cmd_head = shell->cmd;
	data_head = shell->data;
	analyse_exec_buffer(shell);
	shell->data = data_head;
	shell->cmd = cmd_head;
	return (0);
}
