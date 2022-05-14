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
	if (ac != 2)
		error_usage();
	check_map(av[1]);

	ft_putendl_fd("\033[32m ** CHECKS DONE **\033[0m", 1);
	system("leaks so_long");
	return (0);
}
