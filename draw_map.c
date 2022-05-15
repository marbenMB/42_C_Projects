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
	stc->win = mlx_new_window(stc->mlx, (int)ft_strlen(map[0]) * 50, map_height(map) * 50, "MAR_BEN");
	mlx_loop(stc->mlx);
}