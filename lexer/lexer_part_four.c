/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_part_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:59:21 by abellakr          #+#    #+#             */
/*   Updated: 2022/07/04 00:03:57 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//---------------------------------------------------------------
t_data	*oranize_simple_command_list(t_data **simple_command_list)
{
	t_data	*backup;
	t_data	*new_list;

	backup = *simple_command_list;
	new_list = NULL;
	look_for_heredoc(backup, &new_list);
	look_for_rop(backup, &new_list);
	look_for_cmd(backup, &new_list);
	new_list = join_cmds(&new_list);
	free_data(simple_command_list);
	return (new_list);
}

//------------------------------------------------------------- look for heredoc
void	look_for_heredoc(t_data *backup, t_data **new_list)
{
	while (backup)
	{
		if (backup->token == HEREDOC || backup->token == RIP)
			ft_lstadd_back_lexer(new_list, \
			ft_lstnew_lexer(backup->str, backup->token));
		backup = backup->next;
	}
}

//------------------------------------ look for rop and apnd
void	look_for_rop(t_data *backup, t_data **new_list)
{
	while (backup)
	{
		if (backup->token == ROP || backup->token == APND)
			ft_lstadd_back_lexer(new_list, \
			ft_lstnew_lexer(backup->str, backup->token));
		backup = backup->next;
	}
}

//------------------------------------------------------------- look for cmd
void	look_for_cmd(t_data *backup, t_data **new_list)
{
	while (backup)
	{
		if (backup->token == CMD)
			ft_lstadd_back_lexer(new_list, \
			ft_lstnew_lexer(backup->str, backup->token));
		backup = backup->next;
	}
}
