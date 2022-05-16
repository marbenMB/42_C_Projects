/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:48 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/05/15 22:04:49 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_wind(char **map, t_mlx *stc)
{
	int		size_x;
	int		size_y;

	size_x = (int)ft_strlen(map[0]) * 50;
	size_y = map_height(map) * 50;
	stc->win = mlx_new_window(stc->mlx, size_x, size_y, "MAR_BEN");
	mlx_loop(stc->mlx);
}
