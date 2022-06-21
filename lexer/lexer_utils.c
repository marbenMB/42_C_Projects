/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:34:54 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/12 15:45:01 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//------------------------ create  a new node in my list
t_data	*ft_lstnew_lexer(char *data, int token)
{
	t_data	*element;

	element = (t_data *)malloc(sizeof(t_data));
	if (!element)
		return (0);
	element->str = ft_strdup(data);
	element->token = token;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

//------------------------------------ ft_add_back
void	ft_lstadd_back_lexer(t_data **lst, t_data *new)
{
	t_data	*lastnode;

	if (*lst == NULL)
	{
		(*lst) = new;
		return ;
	}
	lastnode = ft_lstlast_lexer(lst);
	new->prev = lastnode;
	lastnode->next = new;
}

//---------------------------------------- find last node int list 
t_data	*ft_lstlast_lexer(t_data **lst)
{
	t_data	*backup;

	backup = *lst;
	if (backup == NULL)
		return (NULL);
	while (backup->next != NULL)
		backup = backup->next;
	return (backup);
}

//----------------------------------------------- check if operator
int	ft_is_operator(char c)
{
	if (ft_strchr("<>|", c))
		return (1);
	return (0);
}

//------------------------------------------------- check special char
int	ft_special_char(char c)
{
	if (ft_strchr("\\#`[]!{};()*&~", c))
		return (1);
	return (0);
}
