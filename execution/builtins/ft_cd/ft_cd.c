/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:44:34 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/05 20:08:01 by mbenbajj         ###   ########.fr       */
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

void	chdir_cases(t_shell *shell, char *path)
{
	if (!path)
		chdir_home(shell);
	else if (!ft_strcmp(path, "-"))
		chdir_old(shell);
	else
		chdir_path(shell, path);
}

int	ft_cd(t_shell *shell)
{
	char	*path;

	path = shell->cmd->cmd_flags[1];
	if (check_path(path) || shell->cmd->cmd_flags[2])
	{
		if (shell->cmd->cmd_flags[1] && shell->cmd->cmd_flags[2])
			error_cd(&shell->env, NULL, TMA);
		ft_status(&shell->env, "1");
		return (1);
	}
	dir_chr(shell, path);
	return (0);
}
