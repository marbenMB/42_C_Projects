/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:17:33 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/04 21:11:08 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/execution.h"

void	error_cmd_arg(t_env **env, char *cmd, char *arg, char *msg)
{
	ft_putstr_fd(cmd, STDERROR);
	ft_putstr_fd(" : ", STDERROR);
	ft_putstr_fd(arg, STDERROR);
	ft_putstr_fd(" : ", STDERROR);
	ft_putendl_fd(msg, STDERROR);
	ft_status(env, FAIL_STAT);
}

void	error_cd(t_env **env, char *arg, char *msg)
{
	ft_putstr_fd("bash", STDERROR);
	ft_putstr_fd(" : ", STDERROR);
	ft_putstr_fd("cd", STDERROR);
	ft_putstr_fd(" : ", STDERROR);
	if (arg && arg[0])
	{
		ft_putstr_fd(arg, STDERROR);
		ft_putstr_fd(" : ", STDERROR);
	}
	ft_putendl_fd(msg, STDERROR);
	ft_status(env, FAIL_STAT);
}

void	error_cd_access(t_env **env)
{
	ft_putstr_fd("cd: error retrieving current directory : ", 2);
	ft_putstr_fd("getcwd: cannot access parent directories: ", 2);
	ft_putendl_fd("No such file or directory", 2);
	ft_status(env, SUCC_STAT);
}
