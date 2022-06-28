/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:45:02 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/28 13:53:59 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/execution.h"

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
}
