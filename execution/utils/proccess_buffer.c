/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccess_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:45:06 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/05 04:41:09 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/execution.h"

// waitpid(pid, &status, 0);
// WEXITSTATUS(status) ==> EXIT_STATUS ;

int	proccess_cmd(t_shell *shell, char *cmd, char *cmd_path)
{
	int		pid;
	char	**incub_env;


	incub_env = NULL;
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
			incub_env = incubate_env(shell->env);
			execve(cmd_path, &shell->cmd->cmd_flags[1], incub_env);
		}
		else
		{
			waitpid(pid, NULL, 0);
			free_tab(incub_env);
		}
		return (1);
	}
	return (0);
}

int	proccess_buff(t_shell *shell)
{
	t_cmd	*cmd_head;
	t_data	*data_head;

	cmd_head = shell->cmd;
	data_head = shell->data;
	while (shell->data)
	{
		// debug_print(shell->data->str, shell->data->token);
		// if (analyse_exec_buff(shell, shell->data) == -1)
		// 	while (shell->data->next && shell->data->next->token != PIPE)
		// 		shell->data = shell->data->next;
		if (analyse_exec_buff(shell, shell->data) == -1)
			return (1);
		shell->data = shell->data->next;
	}
	shell->data = data_head;
	shell->cmd = cmd_head;
	return (0);
}
