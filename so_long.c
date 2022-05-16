/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:22:12 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/05/12 17:22:14 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;
	t_mlx	stc;

	if (ac != 2)
		error_usage();
	map = check_map(av[1]);
	ft_putendl_fd("\033[32m ** CHECKS DONE **\033[0m", 1);
	printf("%zu - %d\n", ft_strlen(map[0]), map_height(map));
	stc.mlx = mlx_init();
	open_wind(map, &stc);
	free_tab(map);
	system("leaks so_long");
	return (0);
}
