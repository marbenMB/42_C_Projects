/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:04:20 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/12 15:47:21 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// ------------------------- check syntax error 
int	check_syntax_error(char *buffer)
{
	size_t	i;
	int		d_quotes;
	int		s_quotes;

	i = -1;
	d_quotes = 0;
	s_quotes = 0;
	while (buffer[++i])
	{
		if (buffer[i] == '\'' && s_quotes == 0 && d_quotes == 0)
			s_quotes = 1;
		else if (buffer[i] == '\'' && s_quotes == 1)
			s_quotes = 0;
		if (buffer[i] == '"' && d_quotes == 0 && s_quotes == 0)
			d_quotes = 1;
		else if (buffer[i] == '"' && d_quotes == 1)
			d_quotes = 0;
		if (s_quotes == 0 && d_quotes == 0)
			if (operator_error(buffer, i) == 1)
				return (1);
	}
	if (s_quotes == 1 || d_quotes == 1 || buffer[0] == '|')
		return (1);
	return (0);
}

//---------------------------------------------------------- operator errors
int	operator_error(char *buffer, int i)
{
	if (ft_special_char(buffer[i]))
		return (1);
	if (ft_is_operator(buffer[i]))
	{
		if (buffer[i] == '<' && buffer[i + 1] != buffer[i] && \
		(ft_special_char(buffer[i + 1]) || ft_is_operator(buffer[i + 1])))
			return (1);
		if (buffer[i] == '>' && buffer[i + 1] != buffer[i] && \
		(ft_special_char(buffer[i + 1]) || ft_is_operator(buffer[i + 1])))
			return (1);
		if (buffer[i] == '<' && buffer[i + 1] == '<' && \
		(ft_special_char(buffer[i + 2]) || ft_is_operator(buffer[i + 2])))
			return (1);
		if (buffer[i] == '>' && buffer[i + 1] == '>' && \
		(ft_special_char(buffer[i + 2]) || ft_is_operator(buffer[i + 2])))
			return (1);
		if (buffer[i] == '|' && buffer[i + 1] == '\0')
			return (1);
	}
	return (0);
}
