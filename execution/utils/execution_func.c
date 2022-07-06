/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 03:44:19 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/06 10:16:47 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/execution.h"

char	**incubate_env(t_env *env)
{
	int		idx;
	char	**incub_env;

	incub_env = (char **)malloc(sizeof(char *) * (lst_size(env) + 1));
	if (!incub_env)
		return (NULL);
	idx = 0;
	while (env)
	{
		incub_env[idx] = get_incubate_tab(env);
		idx++;
		env = env->next;
	}
	incub_env[idx] = NULL;
	return (incub_env);
}

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
