/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_first_part.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:11:13 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/30 16:03:25 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//------------------------- ANALYSE BUFFER
t_data	*analyse_buffer(char *buffer)
{
	t_data	*data;
	t_data	*final_list;
	char	*str;

	data = NULL;
	str = buffer;
	free(buffer);
	buffer = ft_strtrim(str, " ");
	if (check_syntax_error(buffer) == 1)
		return (free(buffer), write (2, "syntax error\n", 13), NULL);
	if (data_reconization1(buffer, &data) == 1)
		return (free_data(&data), free(buffer), \
		write (2, "syntax error\n", 13), NULL);
	final_list = simple_command_analyser(&data);
	return (free(buffer), free_data(&data), final_list);
}

// ----------------------------------- save data and token reconization
int	data_reconization1(char *buffer, t_data **data)
{
	char	quote;

	quote = 0;
	while (*buffer)
	{
		if (*buffer == '|')
		{
			if (pipe_data(&buffer, data) == 1)
				return (1);
		}
		else if (*buffer != '|')
		{
			if (*buffer == '"' || *buffer == '\'')
				quote = *buffer;
			if (word_token(&buffer, data, &quote) == 1)
				return (1);
		}
	}
	return (0);
}

//<----------------------------------------------------------->    word
int	word_token(char **buffer, t_data **data, char *quote)
{
	int		i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = *buffer;
	while (**buffer != '\0')
	{
		i++;
		(*buffer)++;
		quotes_checker(**buffer, quote);
		if (**buffer == '|' && *quote == 0)
			break ;
	}
	str1 = ft_substr(str1, 0, i);
	str2 = ft_strtrim(str1, " ");
	ft_lstadd_back_lexer(data, ft_lstnew_lexer(str2, SIMPLE_CMD));
	free(str1);
	free(str2);
	return (0);
}

//-------------------------------------------------------- 
t_data	*simple_command_analyser(t_data **data)
{
	t_data	*backup;
	t_data	*new_data;

	backup = *data;
	new_data = NULL;
	while (backup)
	{
		if (backup->token == SIMPLE_CMD)
		{
			if (simple_command_check(&new_data, backup->str) == 1)
			{
				free_data(&new_data);
				free_data(data);
				return (NULL);
			}
		}
		else if (backup->token == PIPE)
			ft_lstadd_back_lexer(&new_data, ft_lstnew_lexer("|", PIPE));
		backup = backup->next;
	}
	return (new_data);
}

//----------------------------------------- simple command check
int	simple_command_check(t_data **new_data, char *simple_command)
{
	t_data	*simple_command_list;
	t_data	*head;

	simple_command_list = NULL;
	if (data_reconization2(simple_command, &simple_command_list) == 1)
	{
		free_data(&simple_command_list);
		write (2, "syntax error\n", 13);
		return (1);
	}
	simple_command_list = oranize_simple_command_list(&simple_command_list);
	head = simple_command_list;
	while (simple_command_list)
	{
		ft_lstadd_back_lexer(new_data, \
		ft_lstnew_lexer(simple_command_list->str, simple_command_list->token));
		simple_command_list = simple_command_list->next;
	}
	simple_command_list = head;
	free_data(&simple_command_list);
	return (0);
}
