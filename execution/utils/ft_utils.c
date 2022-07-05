/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:44:09 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/05 17:26:37 by mbenbajj         ###   ########.fr       */
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
			path = check_cmd_access(env_paths, cmd);
		free_tab(env_paths);
		if (!path)
			error_cmd_nf(&env, cmd, CNF);
	}
	return (path);
}

char	**incubate_env(t_env *env)
{
	char	*tmp;
	int		idx;
	int		shlvl;
	char	**incub_env;

	env = env->next->next;
	incub_env = (char **)malloc(sizeof(char *) * (lst_size(env) + 1));
	if (!incub_env)
		return (NULL);
	idx = 0;
	while (env)
	{
		tmp = ft_strjoin(env->var, "=");
		if (!ft_strcmp(env->var, "SHLVL"))
		{
			shlvl = ft_atoi(env->value);
			incub_env[idx] = ft_strjoin(tmp, ft_itoa(++shlvl));
		}
		else
			incub_env[idx] = ft_strjoin(tmp, env->value);
		free(tmp);
		env = env->next;
		idx++;
	}
	incub_env[idx] = NULL;
	return (incub_env);
}

void	debug_print(char *str, int d)
{
	printf("\033[1;33m	->	%s	****\n\033[0m", str);
	printf("\033[1;33m	->	%d	****\n\033[0m", d);
}
