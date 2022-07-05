/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:45:02 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/05 04:01:54 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/execution.h"

void	check_complete_env(t_shell *shell)
{
	t_env	*head;

	head = get_env_var(shell->env, "PATH");
	if (!head)
		add_env_var(&shell->env, "PATH", _PATH_STDPATH, -1);
	head = get_env_var(shell->env, "OLDPWD");
	if (!head)
		add_env_var(&shell->env, "OLDPWD", "", 0);
	head = get_env_var(shell->env, "OLDPWD");
	if (!head)
		add_env_var(&shell->env, "OLDPWD", "", 0);
	head = get_env_var(shell->env, "PWD");
	if (!head)
		add_env_var(&shell->env, "PWD", shell->env->next->value, 1);
	head = get_env_var(shell->env, "SHLVL");
	if (!head)
		add_env_var(&shell->env, "SHLVL", "1", 1);
}

void	check_set_env(t_shell *shell)
{
	t_env	*head;
	t_env	*set_pwd;

	set_pwd = ft_lstnew_expander("?_PWD", get_wd());
	set_pwd->if_in_env = -1;
	if (shell->env->next)
		shell->env->next->prev = set_pwd;
	head = shell->env->next;
	shell->env->next = set_pwd;
	set_pwd->prev = shell->env;
	set_pwd->next = head;
	check_complete_env(shell);
}

void	check_in_env(t_shell *shell)
{
	t_env	*back_up;

	shell->env->if_in_env = -1;
	back_up = shell->env->next;
	if (back_up)
	{
		while (back_up)
		{
			back_up->if_in_env = 1;
			back_up = back_up->next;
		}
	}
	check_set_env(shell);
}

char	*check_cmd_access(char **env_paths, char *cmd)
{
	char	*tmp;
	char	*path;
	int		idx;

	idx = -1;
	if (cmd[0] == '.' || cmd[0] == '/')
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
	}
	while (env_paths[++idx])
	{
		tmp = ft_strjoin(env_paths[idx], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
	}
	return (NULL);
}
