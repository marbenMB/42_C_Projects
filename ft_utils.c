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

int		map_height(char **map)
{
	int		i;

	i = -1;
	while (map[++i])
		;
	return (i);
}

char	**get_map(int fd)
{
	char	*line;
	char	*str;
	char	*tmp;
	char	**tab;

	line = get_next_line(fd);
	if (!line)
		error_map(NULL);
	str = ft_strjoin(line, "\n");
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
		{
			tmp = str;
			str = ft_strjoin(str, line);
			free(tmp);
		}
	}
	tab = ft_split(str, '\n');
	return (free(str), tab);
}