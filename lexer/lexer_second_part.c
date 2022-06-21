/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_second_part.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:34:02 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/20 10:26:34 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
//-------------------------- 1 check operator type and save operator and data
int	operator_type(char **buffer, t_data **data)
{
	int	flag;

	flag = 0;
	if (**buffer == '|')
	{
		if (pipe_data(buffer, data) == 1)
			return (1);
	}
	else
	{
		if (**buffer == '<' && *(*buffer + 1) == '<')
			flag = HEREDOC;
		else if (**buffer == '>' && *(*buffer + 1) == '>')
			flag = APND;
		else if (**buffer == '<' && *(*buffer + 1) != '<')
			flag = RIP;
		else if (**buffer == '>' && *(*buffer + 1) != '>')
			flag = ROP;
		if (save_operator_data(buffer, data, flag) == 1)
			return (1);
	}
	return (0);
}

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

//-------------------------------------------  3 other operators data
int	save_operator_data(char **buffer, t_data **data, int flag)
{
	int		i;
	char	*str1;
	char	*str2;

	check_flag(buffer, flag);
	str1 = *buffer;
	i = count_cmd_word_len(buffer);
	str1 = ft_substr(str1, 0, i);
	str2 = ft_strtrim(str1, " ");
	if (ft_strcmp(str2, "|") == 0 || ft_strcmp(str2, "<") == 0 || ft_strcmp(str2, "<<") == 0 || ft_strcmp(str2, ">") == 0 || ft_strcmp(str2, ">>") == 0)
	{
		free(str1);
		free(str2);
		return (1);
	}
	ft_lstadd_back_lexer(data, ft_lstnew_lexer(str2, flag));
	free(str1);
	free(str2);
	return (0);
}

//------------------------------------------------------------- 4 check flag 
void	check_flag(char **buffer, int flag)
{
	if (flag == HEREDOC || flag == APND)
		(*buffer) += 2;
	else if (flag == RIP || flag == ROP)
		(*buffer)++;
	while (**buffer == ' ')
		(*buffer)++;
}

//--------------------------------------------------- 5 count cmd_word
int	count_cmd_word_len(char **buffer)
{
	int	i;

	i = 0;
	char	quote;

	quote = 0;
	while (**buffer != '\0')
	{
		quotes_checker(**buffer, &quote);
		i++;
		(*buffer)++;
		if ((ft_is_operator(**buffer) == 1 || **buffer == ' ') && quote == 0)
			break ;
	}
	while (**buffer == ' ')
		(*buffer)++;
	return (i);
}
