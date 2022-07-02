/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:17:33 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/02 01:27:00 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/execution.h"

void	error_cmd_arg(t_env **env, char *cmd, char *arg, char *msg)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(" : ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(" : ", 2);
	ft_putendl_fd(msg, 2);
	ft_status(env, FAIL_STAT);
}

void	error_cd(t_env **env, char *arg, char *msg)
{
	ft_putstr_fd("bash", 2);
	ft_putstr_fd(" : ", 2);
	ft_putstr_fd("cd", 2);
	ft_putstr_fd(" : ", 2);
	if (arg && arg[0])
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(" : ", 2);
	}
	ft_putendl_fd(msg, 2);
	ft_status(env, FAIL_STAT);
}
