/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:44:34 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/04 21:09:15 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/execution.h"

int	chdir_home(t_shell *shell)
{
	t_env	*var;
	int		ch_stat;

	var = get_env_var(shell->env, "HOME");
	if (var)
	{
		ch_stat = chdir(var->value);
		if (ch_stat == -1 && (!var->value))
		{
			error_cd(&shell->env, var->value, HNS);
			return (1);
		}
		else if (ch_stat == -1 && *(var->value) != '\0')
		{
			error_cd(&shell->env, var->value, NSFD);
			return (1);
		}
	}
	else
	{
		error_cd(&shell->env, NULL, HNS);
		return (1);
	}
	ft_status(&shell->env, SUCC_STAT);
	return (0);
}

int	chdir_old(t_shell *shell)
{
	t_env	*var;
	int		ch_stat;

	var = get_env_var(shell->env, "OLDPWD");
	if (var)
	{
		ch_stat = chdir(var->value);
		if (ch_stat == -1)
		{
			if ((!var->value || var->value[0] == '\0'))
				error_cd(&shell->env, var->value, ONS);
			else if (*(var->value) != '\0')
				error_cd(&shell->env, var->value, NSFD);
			return (1);
		}
	}
	else
	{
		error_cd(&shell->env, NULL, HNS);
		return (1);
	}
	ft_putendl_fd(var->value, 1);
	ft_status(&shell->env, SUCC_STAT);
	return (0);
}

int	chdir_path(t_shell *shell, char *path)
{
	if (chdir(path) == -1)
	{
		error_cd(&shell->env, path, NSFD);
		return (1);
	}
	ft_status(&shell->env, SUCC_STAT);
	return (0);
}

void	dir_chr(t_shell *shell, char *path)
{
	char	*old;
	char	*tmp;
	char	*current;

	current = NULL;
	old = NULL;
	if (get_wd())
		old = ft_strdup(get_wd());
	else
		old = ft_strdup(shell->env->next->value);
	if (!path)
		chdir_home(shell);
	else if (!ft_strcmp(path, "-"))
		chdir_old(shell);
	else
		chdir_path(shell, path);
	if (get_wd())
		current = ft_strdup(get_wd());
	else
	{
		if (path)
		{
			error_cd_access(&shell->env);
			tmp = ft_strjoin(shell->env->next->value, "/");
			current = ft_strjoin(tmp, path);
			free(tmp);
		}
	}
	update_wd(&shell->env, old, current);
	free(old);
	free(current);
}

int	ft_cd(t_shell *shell)
{
	char	*path;
	
	path = shell->cmd->cmd_flags[1];
	if (check_path(path) || shell->cmd->cmd_flags[2])
	{
		if (shell->cmd->cmd_flags[2])
			error_cd(&shell->env, NULL, TMA);
		ft_status(&shell->env, "1");
		return (1);
	}
	dir_chr(shell, path);
	return (0);
}
