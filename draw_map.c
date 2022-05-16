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

void	create_components(t_mlx *stc)
{
	int	x;
	int	y;

	stc->wall = mlx_xpm_file_to_image(stc->mlx, "img_src/grass.xpm", &x, &y);
	stc->bg = mlx_xpm_file_to_image(stc->mlx, "img_src/enemy.xpm", &x, &y);
	stc->player = mlx_xpm_file_to_image(stc->mlx, "img_src/player.xpm", &x, &y);
	stc->out = mlx_xpm_file_to_image(stc->mlx, "img_src/door.xpm", &x, &y);
	stc->collect = mlx_xpm_file_to_image(stc->mlx, "img_src/coin.xpm", &x, &y);
}

void	ft_draw(t_mlx *stc)
{
	int	dx;
	int	dy;
	int	x;
	int	y;

	dx = -1;
	y = 0;
	while (stc->map[++dx])
	{
		dy = -1;
		x = 0;
		while(stc->map[dx][++dy])
		{
			if (stc->map[dx][dy] == '1')
				mlx_put_image_to_window(stc->mlx, stc->win, stc->wall, x, y);
			else if (stc->map[dx][dy] == 'C')
				mlx_put_image_to_window(stc->mlx, stc->win, stc->collect, x, y);
			else if (stc->map[dx][dy] == 'P')
				mlx_put_image_to_window(stc->mlx, stc->win, stc->player, x, y);
			else if (stc->map[dx][dy] == 'E')
				mlx_put_image_to_window(stc->mlx, stc->win, stc->out, x, y);
			x += 50;
		}
		y += 50;
	}
}

void	open_wind(char **map, t_mlx *stc)
{
	int		size_x;
	int		size_y;

	size_x = (int)ft_strlen(map[0]) * 50;
	size_y = map_height(map) * 50;
	stc->win = mlx_new_window(stc->mlx, size_x, size_y, "MAR_BEN");
	create_components(stc);
	ft_draw(stc);
	mlx_loop(stc->mlx);
}
