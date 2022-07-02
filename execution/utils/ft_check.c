/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:45:02 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/02 00:31:06 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/execution.h"

void	check_in_env(t_shell *shell)
{
	t_env	*back_up;
	t_env	*head;

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
	head = get_env_var(shell->env, "OLDPWD");
	if (!head)
		add_env_var(&shell->env, "OLDPWD", "", 0);
}
