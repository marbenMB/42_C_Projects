/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:00:23 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/05/12 18:00:24 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_name(char *name)
{
	char	*extension;

	if (ft_strlen(name) <= 4)
		error_name();
	extension = ft_substr(name, ft_strlen(name) - 4, 4);
	if (ft_strcmp(extension, ".ber"))
		error_name();
	free(extension);
}

void	check_wall(char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		if (i == 0 || i == map_height(map) - 1)
		{
			j = -1;
			while (map[i][++j])
			{
				if (map[i][j] != '1')
					error_map(map);
			}
		}
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			error_map(map);
	}
}

void	check_components(char **map)
{
	check_wall(map);
	// check_elem(map);
}

void	check_map(char *name)
{
	int		fd;
	char	**map;

	check_name(name);
	fd = open(name, O_RDONLY, 0666);
	if (fd < 0)
		error_file();
	map = get_map(fd);
	check_components(map);
	free_tab(map);
}
