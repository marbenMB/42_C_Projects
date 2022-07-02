/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:41:34 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/02 02:21:43 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/execution.h"

int	is_flag(char *word)
{
	int		idx;

	idx = -1;
	if (word[++idx] && word[idx] == '-')
	{
		while (word[++idx] && word[idx] == 'n')
			;
		if (word[idx] && word[idx] != 'n')
			return (0);
	}
	if (!word[idx] && idx > 1)
		return (1);
	return (0);
}

int	ft_echo(t_shell *shell)
{
	int		_n;
	int		idx;

	_n = 1;
	idx = 1;
	while (shell->cmd->cmd_flags[idx] && is_flag(shell->cmd->cmd_flags[idx]))
	{
		_n = 0;
		idx++;
	}
	while (shell->cmd->cmd_flags[idx])
	{
		ft_putstr_fd(shell->cmd->cmd_flags[idx], STDOUT);
		if (shell->cmd->cmd_flags[idx + 1])
			ft_putstr_fd(" ", STDOUT);
		idx++;
	}
	if (_n)
		ft_putstr_fd("\n", STDOUT);
	ft_status(&shell->env, SUCC_STAT);
	return (0);
}
