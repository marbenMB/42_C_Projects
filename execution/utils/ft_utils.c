/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:44:09 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/02 02:13:51 by mbenbajj         ###   ########.fr       */
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

void	debug_print(char *str, int d)
{
	printf("\033[1;33m	->	%s	****\n\033[0m", str);
	printf("\033[1;33m	->	%d	****\n\033[0m", d);
}
