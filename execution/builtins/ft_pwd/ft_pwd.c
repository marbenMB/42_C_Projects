/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:42:31 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/29 13:33:43 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/execution.h"

int	ft_pwd(t_shell *shell)
{
	char	*path;
	char	cwd[PATH_MAX];

	path = getcwd(cwd, sizeof(cwd));
	// if (!path)
	// 	error();
	
	printf("%s\n", path);
	if (path)
		ft_status(&shell->env, "0");
	return (0);
}
