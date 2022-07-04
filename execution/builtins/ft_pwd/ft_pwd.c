/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:42:31 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/04 20:27:43 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/execution.h"

int	ft_pwd(t_shell *shell)
{
	char	*path;
	t_env	*head;
	char	cwd[PATH_MAX];

	path = getcwd(cwd, sizeof(cwd));
	if (path)
	{	
		ft_putendl_fd(path, 1);
		ft_status(&shell->env, SUCC_STAT);
	}
	else if (!path)
	{
		head = get_env_var(shell->env, "?_PWD");
		ft_putendl_fd(head->value, 1);
		ft_status(&shell->env, SUCC_STAT);
	}
	else
		ft_status(&shell->env, FAIL_STAT);
	return (0);
}
