/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:42:14 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/25 20:54:38 by mbenbajj         ###   ########.fr       */
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

int	add_env_var(t_shell *shell)
{
	int		idx[2];
	int		if_in_env;
	char	*new_var;
	char	*new_value;

	idx[0] = 1;
	while (shell->cmd->cmd_flags[idx[0]])
	{
		if_in_env = 0;
		idx[1] = 0;
		while (shell->cmd->cmd_flags[idx[0]][idx[1]] && shell->cmd->cmd_flags[idx[0]][idx[1]] != '=')
			idx[1]++;
		new_var = ft_substr(shell->cmd->cmd_flags[idx[0]], 0, idx[1]);
		if (shell->cmd->cmd_flags[idx[0]][idx[1]] && shell->cmd->cmd_flags[idx[0]][idx[1]] == '=')
		{
			if_in_env = 1;
			idx[1]++;
		}
		new_value = ft_substr(shell->cmd->cmd_flags[idx[0]], idx[1], ft_strlen(shell->cmd->cmd_flags[0]));
		ft_lstadd_back_expander(&shell->env, ft_lstnew_expander(new_var, new_value));
		ft_lstlast_expander(&shell->env)->if_in_env = if_in_env;
		free(new_value);
		free(new_var);
		idx[0]++;
	}
	return (0);
}


//	*************************************************************************	//
//	                                                                         	//
//	                                                                         	//
//	                                                                         	//
//	*************************************************************************	//

int	ft_export(t_shell *shell)
{
	if (!shell->cmd->cmd_flags[1])
		print_sorted_env(shell->env);
	else
	{
		add_env_var(shell);
	}
	return (0);
}
