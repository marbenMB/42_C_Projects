/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:42:14 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/28 13:50:26 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/execution.h"

char	**get_var_tab(t_env *env)
{
	char	**tab_var;
	int		i;

	tab_var = (char **)malloc(sizeof(char *) * lst_size(env));
	i = 0;
	env = env ->next;
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
	head = env->next;
	i = 0;
	while (tab_var[i])
	{
		head = env->next;
		while (head)
		{
			if (!ft_strcmp(tab_var[i], head->var))
				print_env_var(head->var, head->value);
			head = head->next;
		}
		i++;
	}
	free_tab(tab_var);
	return (0);
}

int	add_env_var(t_env **env, char *var_str)
{
	int		idx;
	int		if_in_env;
	char	*new_var;
	char	*new_value;

	if_in_env = 0;
	idx = 0;
	while (var_str[idx] && var_str[idx] != '=')
		idx++;
	new_var = ft_substr(var_str, 0, idx);
	if (var_str[idx] && var_str[idx] == '=')
	{
		if_in_env = 1;
		idx++;
	}
	new_value = ft_substr(var_str, idx, ft_strlen(var_str));
	ft_lstadd_back_expander(env, ft_lstnew_expander(new_var, new_value));
	ft_lstlast_expander(env)->if_in_env = if_in_env;
	free(new_value);
	free(new_var);
	return (0);
}

//	***********************************************************	   //
//	                                                       	       //
//	                                                               //
//	                                                               //
//	***********************************************************	   //

// int	valid_name(t_shell *shell)
// {

// }

int	env_var(t_shell *shell)
{	
	int		i;

	i = 1;
	while (shell->cmd->cmd_flags[i])
	{
		if (valid_name(shell))
			add_env_var(&shell->env, shell->cmd->cmd_flags[i]);
		else
			// error_cmd_arg();
		i++;
	}
	return (0);
}

int	ft_export(t_shell *shell)
{
	if (!shell->cmd->cmd_flags[1])
		print_sorted_env(shell->env);
	else
	{
		env_var(shell);
	}
	return (0);
}
