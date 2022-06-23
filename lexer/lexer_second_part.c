/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_second_part.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:34:02 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/22 22:57:38 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
//------------------------------------------------------------ 2  store pipe
int	pipe_data(char **buffer, t_data **data)
{
	ft_lstadd_back_lexer(data, ft_lstnew_lexer("|", PIPE));
	(*buffer)++;
	while (**buffer == ' ')
		(*buffer)++;
	if (**buffer == '|')
		return (1);
	return (0);
}
// ------------------------------------------------------------------------
int	operator_type(char **simple_command, t_data **simple_command_list)
{
	int	flag;

	flag = 0;
	if (**simple_command == '<' && *(*simple_command + 1) == '<')
		flag = HEREDOC;
	else if (**simple_command == '>' && *(*simple_command + 1) == '>')
		flag = APND;
	else if (**simple_command == '<' && *(*simple_command + 1) != '<')
		flag = RIP;
	else if (**simple_command == '>' && *(*simple_command + 1) != '>')
		flag = ROP;
	if (save_operator_data(simple_command, simple_command_list, flag) == 1)
		return (1);
	return (0);
}
//-------------------------------------------  3 other operators data
int	save_operator_data(char **simple_command, t_data **simple_command_list, int flag)
{
	int		i;
	char	*str1;
	char	*str2;

	check_flag(simple_command, flag);
	str1 = *simple_command;
	i = 	files_lim_len(simple_command);
	str1 = ft_substr(str1, 0, i);
	str2 = ft_strtrim(str1, " ");
	if (ft_strcmp(str2, "|") == 0 || ft_strcmp(str2, "<") == 0 || ft_strcmp(str2, "<<") == 0 || ft_strcmp(str2, ">") == 0 || ft_strcmp(str2, ">>") == 0)
	{
		free(str1);
		free(str2);
		return (1);
	}
	ft_lstadd_back_lexer(simple_command_list, ft_lstnew_lexer(str2, flag));
	free(str1);
	free(str2);
	return (0);
}
//------------------------------------------------------------- 4 check flag 
void	check_flag(char **simple_command, int flag)
{
	if (flag == HEREDOC || flag == APND)
		(*simple_command) += 2;
	else if (flag == RIP || flag == ROP)
		(*simple_command)++;
	while (**simple_command == ' ')
		(*simple_command)++;
}
//--------------------------------------------------- 5 count cmd_word
int	files_lim_len(char **simple_command)
{
	int	i;

	i = 0;
	char	quote;

	quote = 0;
	while (**simple_command != '\0')
	{
		quotes_checker(**simple_command, &quote);
		i++;
		(*simple_command)++;
		if ((ft_is_operator(**simple_command) == 1 || **simple_command == ' ') && quote == 0)
			break ;
	}
	while (**simple_command == ' ')
		(*simple_command)++;
	return (i);
}