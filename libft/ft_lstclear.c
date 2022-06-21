/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:57:06 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/10 02:27:53 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*backup;

	if (lst)
	{
		while (*lst)
		{
			backup = (*lst)->next;
			ft_lstdelone (*lst, del);
			*lst = backup;
		}
	}
}
