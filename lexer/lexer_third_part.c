/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_third_part.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:57:53 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/28 22:07:33 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//-------------------------------------------------------
int	data_reconization2(char *simple_command, t_data **simple_command_list)
{
	char	quote;

	quote = 0;
	while (*simple_command)
	{
		if (ft_is_operator(*simple_command) == 1)
		{
			if (operator_type(&simple_command, simple_command_list) == 1)
				return (1);
		}
		else if (ft_is_operator(*simple_command) == 0)
		{
			if (*simple_command == '"' || *simple_command == '\'')
				quote = *simple_command;
			if (cmd_token(&simple_command, simple_command_list, &quote) == 1)
				return (1);
		}
	}
	return (0);
}

//-------------------------------------------------------------------- cmd token
int	cmd_token(char **simple_command, t_data **simple_command_list, char *quote)
{
	int		i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = *simple_command;
	while (**simple_command != '\0')
	{
		i++;
		(*simple_command)++;
		quotes_checker(**simple_command, quote);
		if (ft_is_operator(**simple_command) == 1 && *quote == 0)
			break ;
	}
	str1 = ft_substr(str1, 0, i);
	str2 = ft_strtrim(str1, " ");
	ft_lstadd_back_lexer(simple_command_list, ft_lstnew_lexer(str2, CMD));
	free(str1);
	free(str2);
	return (0);
}

//------------------------------------------------------
t_data	*join_cmds(t_data **new_list_cmd)
{
	t_data	*backup;
	t_data	*new_list;
	char	*str1;
	char	*str2;

	backup = *new_list_cmd;
	new_list = NULL;
	str1 = NULL;
	str2 = NULL;
	while (backup)
	{	
		if (backup->token != CMD)
			ft_lstadd_back_lexer(&new_list, \
			ft_lstnew_lexer(backup->str, backup->token));
		backup = backup->next;
	}
	str1 = join_cmds_string(*new_list_cmd);
	if (str1 != NULL)
	{
		str2 = ft_strtrim(str1, " ");
		ft_lstadd_back_lexer(&new_list, ft_lstnew_lexer(str2, CMD));
		free (str1);
		free (str2);
	}
	return (free_data(new_list_cmd), new_list);
}

//----------------------- function 2 return joined cmd and its flags 
char	*join_cmds_string(t_data *list)
{
	t_data	*backup;
	char	*str1;
	char	*str2;

	backup = list;
	str1 = NULL;
	str2 = NULL;
	while (backup)
	{
		if (backup->token == CMD)
		{
			str2 = ft_strjoin(str1, " ");
			free(str1);
			str1 = ft_strjoin(str2, backup->str);
			free(str2);
		}
		backup = backup->next;
	}
	return (str1);
}
