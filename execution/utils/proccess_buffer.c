/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccess_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:45:06 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/06 11:45:53 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/execution.h"

void	check_exit_stat(t_shell *shell, int i_stat)
{
	char	*s_stat;

	if (WIFEXITED(i_stat))
		i_stat = WEXITSTATUS(i_stat);
	else if (WIFSIGNALED(i_stat))
		i_stat += 128;
	s_stat = ft_itoa(i_stat);
	ft_status(&shell->env, s_stat);
	free(s_stat);
}

int	proccess_cmd(t_shell *shell, char *cmd, char *cmd_path, int *pip_fd)
{
	if (if_cmd_builtin(cmd) == 1 && shell->pipe_p == 0)
	{
		ft_dup_io(shell, pip_fd);
		execute_builtin(shell, cmd);
	}
	else
	{
		if (if_cmd_builtin(cmd) == 1)
			execute_builtin_child(shell, cmd, pip_fd);
		else if (if_cmd_builtin(cmd) == 0)
			execute_non_builtin(shell, cmd_path, pip_fd);
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
