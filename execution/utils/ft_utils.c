/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:44:09 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/06/28 13:54:30 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/execution.h"

t_cmd	*lstnew(char	**cmd)
{
	t_cmd	*new_list;

	new_list = (t_cmd *)malloc(sizeof(*new_list));
	if (new_list == NULL)
		return (NULL);
	new_list -> cmd_flags = cmd;
	new_list -> next = NULL;
	return (new_list);
}

void	add_back(t_cmd **lst, t_cmd *cmd)
{
	if (!*lst)
		*lst = cmd;
	else
		(*lst)->next = cmd;
}

int	fill_cmd(t_shell *shell)
{
	t_data		*head;
	t_cmd		*cmd;

	head = shell->data;
	while (head)
	{
		if (head->token == 8)
			add_back(&cmd, lstnew(ft_split(head->str, ' ')));
		head = head->next;
	}
	shell->cmd = cmd;
	proccess_buff(shell);
	free(cmd);
	return (0);
}
