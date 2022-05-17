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
	t_mlx	stc;

	if (ac != 2)
		error_usage();
	stc_init(&stc);
	stc.map = check_map(av[1]);
	ft_putendl_fd("\033[32m ** CHECKS DONE **\033[0m", 1);
	printf("%zu - %d\n", ft_strlen(stc.map[0]), map_height(stc.map));
	open_wind(&stc);
	free_tab(stc.map);
	// system("leaks so_long");
	return (0);
}
