/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 23:09:49 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/04 21:22:32 by mbenbajj         ###   ########.fr       */
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
	head = get_env_var((*env), "?_PWD");
	if (head)
	{
		free(head->value);
		head->value = ft_strdup(current);
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

char	*path_join(char *old, char *path)
{
	char	*tmp;
	char	*current;

	tmp = ft_strjoin(old, "/");
	current = ft_strjoin(tmp, path);
	free(tmp);
	return (current);
}

void	dir_chr(t_shell *shell, char *path)
{
	char	*old;
	char	*current;

	current = NULL;
	old = NULL;
	if (get_wd())
		old = ft_strdup(get_wd());
	else
		old = ft_strdup(shell->env->next->value);
	chdir_cases(shell, path);
	if (get_wd())
		current = ft_strdup(get_wd());
	else
	{
		if (path)
		{
			error_cd_access(&shell->env);
			current = path_join(shell->env->next->value, path);
		}
	}
	update_wd(&shell->env, old, current);
	free(old);
	free(current);
}
