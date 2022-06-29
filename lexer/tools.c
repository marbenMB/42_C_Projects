/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 08:35:24 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/28 22:28:48 by abellakr         ###   ########.fr       */
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

//-------------------------------------------------- function free cmd 
void	free_data3(t_cmd **cmd)
{
	t_cmd	*back_up;

	if (*cmd)
	{
		back_up = *cmd;
		while (*cmd)
		{
			back_up = (*cmd)->next;
			free_twod_tab((*cmd)->cmd_flags);
			free(*cmd);
			*cmd = back_up;
		}
	}
}
