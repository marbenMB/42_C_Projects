/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:44:09 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/06 11:44:59 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/execution.h"

void	ft_status(t_env **env, char *stats)
{
	if ((*env)->if_in_env == -1)
	{
		free((*env)->value);
		(*env)->value = ft_strdup(stats);
	}
}

t_env	*get_env_var(t_env *env, char *var_name)
{
	t_env	*head;

	head = env->next;
	while (head && ft_strcmp((head->var), var_name))
		head = head->next;
	return (head);
}

int	if_cmd_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, "echo") || \
		!ft_strcmp(cmd, "ECHO") || !ft_strcmp(cmd, "env") || \
		!ft_strcmp(cmd, "ENV") || !ft_strcmp(cmd, "pwd") || \
		!ft_strcmp(cmd, "PWD") || !ft_strcmp(cmd, "export") || \
		!ft_strcmp(cmd, "exit") || !ft_strcmp(cmd, "unset"))
		return (1);
	return (0);
}

char	*get_cmd_path(t_env *env, char *cmd)
{
	t_env	*var;
	char	**env_paths;
	char	*path;

	path = NULL;
	env_paths = NULL;
	if (!if_cmd_builtin(cmd))
	{	
		var = get_env_var(env, "PATH");
		if (var)
			env_paths = ft_split(var->value, ':');
		if (env_paths)
		{
			path = check_cmd_access(env_paths, cmd);
			free_tab(env_paths);
		}
		if (!path)
			error_cmd_nf(&env, cmd, CNF);
	}
	return (path);
}

char	*get_incubate_tab(t_env *env)
{
	char	*tab;
	char	*tmp;
	int		shlvl;

	tab = NULL;
	if (env->if_in_env == 1)
	{
		tmp = ft_strjoin(env->var, "=");
		if (!ft_strcmp(env->var, "SHLVL"))
		{
			shlvl = ft_atoi(env->value);
			tab = ft_strjoin(tmp, ft_itoa(++shlvl));
		}
		else
			tab = ft_strjoin(tmp, env->value);
		free(tmp);
	}
	return (tab);
}
