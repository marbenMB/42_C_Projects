/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 08:35:24 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/13 10:33:07 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//-------------------------------------------------- function free data
void	free_data(t_data **data)
{
	t_data	*back_up;

	if (*data)
	{
		back_up = *data;
		while (*data)
		{
			back_up = (*data)->next;
			free((*data)->str);
			free(*data);
			*data = back_up;
		}
	}
}
//-------------------------------------------------- function free data
void	free_data2(t_env **env)
{
	t_env	*back_up;

	if (*env)
	{
		back_up = *env;
		while (*env)
		{
			back_up = (*env)->next;
			free((*env)->var);
			free((*env)->value);
			free(*env);
			*env = back_up;
		}
	}
}
