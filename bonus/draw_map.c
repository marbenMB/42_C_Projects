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
	int		x;
	int		y;

	stc->wall = mlx_xpm_file_to_image(stc->mlx, "img_src/grass.xpm", &x, &y);
	stc->player = mlx_xpm_file_to_image(stc->mlx, "img_src/player.xpm", &x, &y);
	stc->out = mlx_xpm_file_to_image(stc->mlx, "img_src/door.xpm", &x, &y);
	stc->collect = mlx_xpm_file_to_image(stc->mlx, "img_src/coin.xpm", &x, &y);
	stc->bg = mlx_xpm_file_to_image(stc->mlx, "img_src/space.xpm", &x, &y);
	if (!stc->wall || !stc->player || !stc->out || !stc->collect || !stc->bg)
		ft_close(stc);
}

void	ft_paint(t_mlx *stc, void *img, int dy, int dx)
{
	mlx_put_image_to_window(stc->mlx, stc->win, img, dy, dx);
}

void	ft_draw(t_mlx *stc)
{
	int	dx;
	int	dy;

	dx = -1;
	while (stc->map[++dx])
	{
		dy = -1;
		while (stc->map[dx][++dy])
		{
			if (stc->map[dx][dy] == '1')
				ft_paint(stc, stc->wall, dy * 50, dx * 50);
			else if (stc->map[dx][dy] == 'C')
				ft_paint(stc, stc->collect, dy * 50, dx * 50);
			else if (stc->map[dx][dy] == 'P')
				ft_paint(stc, stc->player, dy * 50, dx * 50);
			else if (stc->map[dx][dy] == 'E')
				ft_paint(stc, stc->out, dy * 50, dx * 50);
			else if (stc->map[dx][dy] == '0')
				ft_paint(stc, stc->bg, dy * 50, dx * 50);
		}
	}
}

void	open_wind(t_mlx *stc)
{
	int		size_x;
	int		size_y;

	size_x = (int)ft_strlen(stc->map[0]) * 50;
	size_y = map_height(stc->map) * 50;
	stc->mlx = mlx_init();
	stc->win = mlx_new_window(stc->mlx, size_x, size_y, "MAR_BEN");
	create_components(stc);
	ft_draw(stc);
	mlx_hook(stc->win, 02, 0, key_hook, stc);
	mlx_hook(stc->win, 17, 0, ft_close, stc);
	mlx_loop(stc->mlx);
}
