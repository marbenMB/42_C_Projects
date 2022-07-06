/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 03:44:19 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/06 04:00:10 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/execution.h"

void	dup_next(t_shell *shell, int *pip_fd)
{
	if (shell->data->prev && (shell->data->prev->token == ROP \
			|| shell->data->prev->token == APND))
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

void	dup_no_next(t_shell *shell, int *pip_fd)
{
	if (shell->data->prev && (shell->data->prev->token == ROP \
		|| shell->data->prev->token == APND))
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
