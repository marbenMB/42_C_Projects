/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccess_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:45:06 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/04 22:59:46 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/execution.h"

// waitpid(pid, &status, 0);
// WEXITSTATUS(status) ==> EXIT_STATUS ;

int	proccess_cmd(t_shell *shell, char *cmd)
{
	int		pid;
	
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
		//	execve -> execution
		pid = fork();
		if (pid < 0)
			error_internal_ft(&shell->env, "fork", FIE);
		else if (pid == 0)
		{
			ft_putendl_fd("**", 1);
			//*	incubate_env() -> pass two dementionnal env array to execve
			//*	get_cmd_path() -> get command path
			//? if path == X_OK
			// execve();
			//? esle if path != X_OK
			//! error_cmd_nf(&shell->env, cmd, CNF);
		}
		else
			waitpid(pid, NULL, 0);
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
		// if (shell->data->token == 8)
		// 	proccess_cmd(shell, shell->cmd->cmd_flags[0]);
		debug_print(shell->data->str, shell->data->token);
		shell->data = shell->data->next;
	}
	shell->data = data_head;
	shell->cmd = cmd_head;
	return (0);
}
