/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:46:03 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/28 23:27:08 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//------------------------ 
t_cmd	*ft_lstnew_cmd(char **cmd_flags)
{
	t_cmd	*element;
	int		len;

	len = 0;
	element = (t_cmd *)malloc(sizeof(t_cmd));
	while (cmd_flags[len])
		len++;
	element->cmd_flags = (char **)malloc(sizeof(char *) * len + 1);
	len = 0;
	while (cmd_flags[len])
	{
		element->cmd_flags[len] = ft_strdup(cmd_flags[len]);
		len++;
	}
	element->cmd_flags[len] = NULL;
	if (!element)
		return (0);
	element->prev = NULL;
	element->next = NULL;
	return (element);
}

//------------------------------------ ft_add_back
void	ft_lstadd_back_cmd(t_cmd **lst, t_cmd *new)
{
	t_cmd	*lastnode;

	if (*lst == NULL)
	{
		(*lst) = new;
		return ;
	}
	lastnode = ft_lstlast_cmd(lst);
	new->prev = lastnode;
	lastnode->next = new;
}

//---------------------------------------- find last node int list 
t_cmd	*ft_lstlast_cmd(t_cmd **lst)
{
	t_cmd	*backup;

	backup = *lst;
	if (backup == NULL)
		return (NULL);
	while (backup->next != NULL)
		backup = backup->next;
	return (backup);
}
