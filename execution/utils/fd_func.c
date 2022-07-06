/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:22:03 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/06 10:41:42 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/execution.h"

t_fd	*lst_fd_new(int fd)
{
	t_fd	*new;

	new = ft_calloc(1, sizeof(*new));
	new->fd = ft_calloc(1, sizeof(int));
	new->fd = &fd;
	new->next = NULL;
	return (new);
}

t_fd	*last_fd(t_fd *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_fd_back(t_fd **lst, t_fd *new)
{
	if (!(*lst))
		(*lst) = new;
	else
		last_fd((*lst))->next = new;
}
