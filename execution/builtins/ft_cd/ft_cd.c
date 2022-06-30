/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:44:34 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/30 15:30:28 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/execution.h"

int	check_path(char *path)
{
	if (path && path[0])
	{
		if (path[0] == '-' && ft_strlen(path) > 1)
			return (0);
		
	}
	return (0);
}

int ft_cd(t_shell *shell)
{
	char *path;

	path = shell->cmd->cmd_flags[1];
	if (check_path(path))
	{
		ft_status(&shell->env, "1");	
		return (1);
	}
	if (!path)
	{
		//	if !HOME -> bash : cd : HOME not set
		//	cd -> HOME
		/* 	set -> NEW_ENV
		{
				set -> NEW_PWD
				set -> NEW_OLDPWD
		} */
	}
	else if (!ft_strcmp(path, "-"))
	{
		//	if !OLDPWD -> bash : cd : OLDPWD not set
		//	cd -> OLDPWD
		/* 	set -> NEW_ENV
		{
				set -> NEW_PWD
				set -> NEW_OLDPWD
		} */
	}
	else if (path && *path)
	{
		chdir(path);
		/* 	set -> NEW_ENV
		{
				set -> NEW_PWD
				set -> NEW_OLDPWD
		} */
	}
	return (0);
}
