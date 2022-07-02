/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 23:09:49 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/02 00:54:24 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/execution.h"

int	check_path(char *path)
{
	if (path && path[0])
	{
		if (path[0] == '-' && ft_strlen(path) > 1)
			return (1);
	}
	return (0);
}

int	update_wd(t_env **env, char *old, char *current)
{
	t_env	*head;

	head = get_env_var((*env), "OLDPWD");
	if (head)
	{
		free(head->value);
		head->value = ft_strdup(old);
	}
	head = get_env_var((*env), "PWD");
	if (head)
	{
		free(head->value);
		head->value = ft_strdup(current);
	}
	return (0);
}

char	*get_wd(void)
{
	char	cwd[PATH_MAX];

	return (getcwd(cwd, sizeof(cwd)));
}
