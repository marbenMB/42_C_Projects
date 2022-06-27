/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:41:48 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/25 20:41:51 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/execution.h"

int	ft_env(t_shell *shell)
{
	t_env	*head;

	// if (shell->cmd->cmd_flags[1] != NULL)
		// env : arg : No such file or directory
	head = shell->env->next;
	while (head)
	{
		if (head->if_in_env == 1)
			printf("%s=%s\n", head->var, head->value);
		head = head->next;
	}
	return (0);
}
