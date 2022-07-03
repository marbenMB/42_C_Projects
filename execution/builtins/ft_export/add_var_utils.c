/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:49:02 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/03 15:07:37 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/execution.h"

char	*get_var_name(char *var_str)
{
	int		idx;
	char	*var;

	idx = 0;
	while (var_str[idx] && var_str[idx] != '=')
		idx++;
	if (var_str[idx] == '=' && var_str[idx - 1] == '+')
		idx--;
	var = ft_substr(var_str, 0, idx);
	return (var);
}

t_env	*get_existed_var(t_env **env, char *var)
{
	while ((*env))
	{
		if (!ft_strcmp(var, (*env)->var))
			break ;
		(*env) = (*env)->next;
	}
	return ((*env));
}

int	existed_var(t_env *env, char *var)
{
	while (env)
	{
		if (!ft_strcmp(var, env->var))
			return (1);
		env = env->next;
	}
	return (0);
}
