/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:25:07 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/28 18:21:12 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/execution.h"

t_env	*get_existed_var(t_env **env, char *var)
{
	while ((*env))
	{
		if (!ft_strcmp(var, (*env)->var))
			break;
		(*env) = (*env)->next;
	}
	return ((*env));
}

int	add_env_var(t_env **env, char *var, char *value, int _if)
{
	t_env	*head;

	if (existed_var((*env)->next, var))
	{
		head = (*env)->next;
		head = get_existed_var(&head, var);
		free(head->value);
		head->value = ft_strdup(value);
	}
	else
	{
		ft_lstadd_back_expander(env, ft_lstnew_expander(var, value));
		ft_lstlast_expander(env)->if_in_env = _if;
	}
	return (0);
}

int	join_env_value(t_env **env, char *var, char *value)
{
	char	*new_value;
	t_env	*head;

	if (existed_var((*env)->next, var))
	{
		head = (*env)->next;
		head = get_existed_var(&head, var);
		if (head->value)
		{
			new_value = ft_strjoin(head->value, value);
			free(head->value);
			head->value = new_value;
		}
		else
			head->value = ft_strdup(value);
	}
	else
		add_env_var(env, var, value, 1);
	return (0);
}

void    parse_var_str(t_env **env, char *var_str)
{
	char    *var;
	char    *value;
	int     i;
	int     _if;
	
	i = 0;
	_if = 0;
	var = get_var_name(var_str);
	if (var_str[ft_strlen(var)] == '+')
		i = 1;
	if (var_str[ft_strlen(var)] == '=' || var_str[ft_strlen(var) + i] == '=')
		_if = 1;
	value = ft_substr(var_str, ft_strlen(var) + i, ft_strlen(var_str));
	if (i)
		join_env_value(env, var, value);
	else
		add_env_var(env, var, value, _if);
	free(var);
	free(value);
}
