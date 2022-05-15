/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:52:07 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/05/12 17:52:09 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(char **tab)
{
	free_tab(tab);
	ft_putendl_fd("\033[31m Error ** Map Error **\033[0m", 2);
	system("leaks so_long");
	exit (EXIT_FAILURE);
}

void	error_file(void)
{
	ft_putendl_fd("\033[31m Error ** No such file **\033[0m", 2);
	exit (EXIT_FAILURE);
}

void	error_name(void)
{
	ft_putendl_fd("\033[31m Error ** Map Name : name.ber **\033[0m", 2);
	exit (EXIT_FAILURE);
}

void	error_usage(void)
{
	ft_putendl_fd("\033[31m Error ** Usage : ./so_long  map/path **\033[0m", 2);
	exit (EXIT_FAILURE);
}
