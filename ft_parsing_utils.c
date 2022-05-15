/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:26:11 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/05/14 14:26:14 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(char **tab)
{
	int		i;

	i = -1;
	while (tab && tab[++i])
		free(tab[i]);
	free(tab);
}

int	map_height(char **map)
{
	int		i;

	i = -1;
	while (map[++i])
		;
	return (i);
}

char	*joining(char *str, char *line)
{
	char	*tmp;

	tmp = str;
	str = ft_strjoin(str, line);
	free(tmp);
	tmp = str;
	str = ft_strjoin(str, "\n");
	free(tmp);
	return (str);
}

void	check_map_form(char *str, char *line, size_t len)
{
	if (ft_strlen(line) != len)
	{
		free(line);
		free(str);
		error_map(NULL);
	}
}

char	**get_map(int fd)
{
	char	*line;
	char	*str;
	char	**tab;
	size_t	len;

	line = get_next_line(fd);
	if (!line)
		error_map(NULL);
	len = ft_strlen(line);
	str = ft_strjoin(line, "\n");
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
		{
			str = joining(str, line);
			check_map_form(str, line, len);
		}
	}
	tab = ft_split(str, '\n');
	return (free(str), tab);
}
