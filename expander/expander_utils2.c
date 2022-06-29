/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:54:06 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/28 23:26:33 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//------------------------------------------ count words in    string
int	words_counter(char *cmd)
{
	int		count;
	char	quote_type;

	quote_type = 0;
	count = 0;
	while (*cmd)
	{
		quotes_checker(*cmd, &quote_type);
		if (quote_type == 0)
			count_words_witout_quotes(&cmd, &count);
		else if (quote_type != 0)
			count_words_with_quotes(&cmd, &count, &quote_type);
		if (quote_type == 0 && *cmd == ' ')
		{
			while (*cmd == ' ')
				cmd++;
		}
	}
	return (count);
}

//------------------------------------- count words inside quotes
void	count_words_witout_quotes(char **cmd, int *count)
{
	while (**cmd)
	{
		(*cmd)++;
		if (**cmd == ' ' || **cmd == '\'' || **cmd == '"')
			break ;
	}
	if (**cmd == ' ' || **cmd == '\0')
		(*count)++;
}

//----------------------------------- count words inside quotes
void	count_words_with_quotes(char **cmd, int *count, char *quote_type)
{
	while (**cmd)
	{
		(*cmd)++;
		if (**cmd == *quote_type)
			break ;
	}
	quotes_checker(**cmd, quote_type);
	(*cmd)++;
	if ((**cmd == ' ' || **cmd == '\0') && *quote_type == 0)
		(*count)++;
}

//---------------------------------- print and free tab
void	free_twod_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free (tab);
}
