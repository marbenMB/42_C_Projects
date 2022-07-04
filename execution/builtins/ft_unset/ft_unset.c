/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:44:53 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/03 17:18:50 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/execution.h"

void	free_env_node(t_env *node)
{
	free(node->var);
	free(node->value);
	free(node);
}

void	unset_var(t_env **var)
{
	if ((*var)->prev)
		(*var)->prev->next = (*var)->next;
	if ((*var)->next)
		(*var)->next->prev = (*var)->prev;
	free_env_node(*var);
}

int	valid_unset_name(char *name)
{
	int		idx;

	idx = 0;
	if (!name[idx] || ft_isdigit(name[idx]))
		return (1);
	while (name[idx])
	{
		if (export_special_char(name[idx]))
			return (1);
		idx++;
	}
	return (0);
}

int	ft_unset(t_shell *shell)
{
	int		idx;
	t_env	*var;
	char	*status;

	idx = 0;
	status = SUCC_STAT;
	while (shell->cmd->cmd_flags[++idx])
	{
		var = shell->env->next;
		if (!valid_unset_name(shell->cmd->cmd_flags[idx]))
		{
			while (var && ft_strcmp((var->var), shell->cmd->cmd_flags[idx]))
				var = var->next;
			if (var)
				unset_var(&var);
			ft_status(&shell->env, status);
		}
		else
		{
			error_cmd_arg(&shell->env, "unset", \
							shell->cmd->cmd_flags[idx], NVI);
			status = FAIL_STAT;
		}
	}
	return (0);
}
