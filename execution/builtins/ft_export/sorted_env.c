/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:22:47 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/04 05:07:01 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/execution.h"

void	print_env_var(char *var_name, char *value)
{
	ft_putstr_fd("declare -x ", 1);
	ft_putstr_fd(var_name, 1);
	if (*value)
	{
		ft_putstr_fd("=\"", 1);
		ft_putstr_fd(value, 1);
		ft_putchar_fd('\"', 1);
	}
	ft_putchar_fd('\n', 1);
}

char	**get_var_tab(t_env *env)
{
	char	**tab_var;
	int		i;

	tab_var = (char **)malloc(sizeof(char *) * lst_size(env));
	i = 0;
	env = env ->next->next;
	while (env)
	{
		tab_var[i] = ft_strdup(env->var);
		env = env->next;
		i++;
	}
	tab_var[i] = NULL;
	tab_var = sort_tab(tab_var);
	return (tab_var);
}

int	print_sorted_env(t_env *env)
{
	char	**tab_var;
	t_env	*head;
	int		i;

	tab_var = get_var_tab(env);
	head = env->next->next;
	i = 0;
	while (tab_var[i])
	{
		head = env->next->next;
		while (head)
		{
			if (!ft_strcmp(tab_var[i], head->var) && (head->if_in_env == 0 || head->if_in_env == 1))
				print_env_var(head->var, head->value);
			head = head->next;
		}
		i++;
	}
	free_tab(tab_var);
	return (0);
}
