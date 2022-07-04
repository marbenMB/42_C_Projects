/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:45:02 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/04 05:08:44 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/execution.h"

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
	head = get_env_var(shell->env, "PATH");
	if (!head)
		add_env_var(&shell->env, "PATH", _PATH_STDPATH, 1);
	head = get_env_var(shell->env, "OLDPWD");
	if (!head)
		add_env_var(&shell->env, "OLDPWD", "", 0);
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
