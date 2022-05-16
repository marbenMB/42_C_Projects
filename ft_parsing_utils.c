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

void	check_map_form(char *str, char *line, size_t len)
{
	if (ft_strlen(line) != len)
	{
		free(line);
		free(str);
		error_map(NULL);
	}
}

char	*joining(char *str, char *line, char *temp, size_t len)
{
	char	*tmp;

	tmp = str;
	str = ft_strjoin(str, line);
	free(tmp);
	check_map_form(str, temp, len);
	free(temp);
	return (str);
}

char	**get_map(int fd)
{
	char	*line;
	char	*temp[2];
	char	**tab;
	size_t	len;

	line = get_next_line(fd);
	if (!line)
		error_map(NULL);
	temp[0] = ft_strtrim(line, "\n");
	len = ft_strlen(temp[0]);
	temp[1] = ft_strjoin(temp[0], "\n");
	free(temp[0]);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		temp[0] = ft_strtrim(line, "\n");
		if (line)
			temp[1] = joining(temp[1], line, temp[0], len);
	}
	if (temp[1][ft_strlen(temp[1]) - 1] == '\n')
		error_map(NULL);
	tab = ft_split(temp[1], '\n');
	return (free(temp[1]), tab);
}
