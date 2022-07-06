/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:44:43 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/06 12:16:24 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/execution.h"

int	check_exit_args(char **cmd_flags)
{
	int		idx;

	idx = 0;
	if (cmd_flags[0] && cmd_flags[1])
		return (2);
	else if (cmd_flags[0])
	{
		if (cmd_flags[0][idx] == '-' || cmd_flags[0][idx] == '+')
			idx++;
		while (cmd_flags[0][idx])
		{
			if (ft_isalpha(cmd_flags[0][idx]))
				return (1);
			idx++;
		}
	}
	return (0);
}

int	ft_atoi_max(const char *str)
{
	long	num;
	int		signe;

	num = 0;
	signe = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -signe;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		num = num * 10 + *str - 48;
		if ((num * signe) < INT_MIN || (num * signe) > INT_MAX)
			return (-1);
		str++;
	}
	return (num * signe);
}

void	ft_exit(t_shell *shell)
{
	int				check;
	unsigned int	status;

	status = 0;
	check = 0;
	check = check_exit_args(&shell->cmd->cmd_flags[1]);
	ft_putendl_fd("exit", 1);
	if (check == 2)
		error_cmd_arg(&shell->env, "Minishell", "exit", TMA);
	else if (check == 1)
	{
		error_cmd_arg(&shell->env, "Minishell", "exit", NAR);
		ft_s_exit (-1);
	}
	else if (check == 0)
	{
		if (shell->cmd->cmd_flags[1])
			status = (unsigned int)ft_atoi_max(shell->cmd->cmd_flags[1]);
		else if (!shell->cmd->cmd_flags[1])
			status = (unsigned int)ft_atoi_max(shell->env->value);
		ft_s_exit (status % 256);
	}
}
