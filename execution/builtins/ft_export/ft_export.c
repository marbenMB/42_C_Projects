/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:42:14 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/29 11:58:32 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/execution.h"

int	export_special_char(char c)
{
	if (ft_strchr("/|\\#`[]!{};()*&~,-+@%%^<>", c))
		return (1);
	return (0);
}

int	valid_name(char *var_str)
{
	int		idx;
	char	*var;

	idx = 0;
	var = get_var_name(var_str);
	if (ft_isdigit(var[idx]))
	{
		free(var);
		return (1);
	}
	while (var[idx])
	{
		if (export_special_char(var[idx]))
		{
			free(var);
			return (1);
		}
		idx++;
	}
	free(var);
	return (0);
}

int	env_var(t_shell *shell)
{	
	int		i;

	i = 1;
	while (shell->cmd->cmd_flags[i])
	{
		if (valid_name(shell->cmd->cmd_flags[i]))
			error_cmd_arg(&shell->env, shell->cmd->cmd_flags[0], \
							shell->cmd->cmd_flags[i], NVI);
		else
		{
			parse_var_str(&shell->env, shell->cmd->cmd_flags[i]);
			ft_status(&shell->env, SUCC_STAT);
		}
		i++;
	}
	return (0);
}

int	ft_export(t_shell *shell)
{
	if (!shell->cmd->cmd_flags[1])
		print_sorted_env(shell->env);
	else
		env_var(shell);
	return (0);
}
