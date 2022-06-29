/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:44:34 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/28 13:48:10 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/execution.h"

int	ft_cd(t_shell *shell)
{
	char	*path;

	path = shell->cmd->cmd_flags[1];
	if (!path)
	{
		//	cd -> HOME
		/* 	set -> NEW_ENV
		{
				set -> NEW_PWD
				set -> NEW_OLDPWD
		} */
	}
	else if (!ft_strcmp(path, "-") || !ft_strcmp(path, "-"))
	{
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
