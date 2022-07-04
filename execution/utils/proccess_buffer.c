/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccess_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:45:06 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/04 00:49:35 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/execution.h"

// waitpid(pid, &status, 0);
// WEXITSTATUS(status) ==> EXIT_STATUS ;

int	proccess_cmd(t_shell *shell, char *cmd)
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
	else
	{
		//	execve -> execution
		return (1);
	}
	return (0);
}

int	proccess_buff(t_shell *shell)
{
	// while (shell->data)
	// {
	if (shell->data->token == 8)
		proccess_cmd(shell, shell->cmd->cmd_flags[0]);
	// 	shell->data = shell->data->next;
	// }
	return (0);
}
