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

int	animation(t_mlx *stc)
{
	static int	i;

	if (i <= 20)
	{
		stc->collect = stc->coin;
		play_animation(stc);
	}
	else if (i > 20 && i <= 40)
	{
		stc->collect = stc->coin_1;
		play_animation(stc);
	}
	else if (i > 40 && i <= 60)
	{
		stc->collect = stc->coin_2;
		play_animation(stc);
	}
	else
		i = 0;
	i++;
	return (i);
}

void	create_components(t_mlx *stc)
{
	int		x;
	int		y;

	stc->wall = mlx_xpm_file_to_image(stc->mlx, "img_src/grass.xpm", &x, &y);
	stc->player = mlx_xpm_file_to_image(stc->mlx, "img_src/player.xpm", &x, &y);
	stc->out = mlx_xpm_file_to_image(stc->mlx, "img_src/door.xpm", &x, &y);
	stc->collect = mlx_xpm_file_to_image(stc->mlx, "img_src/coin.xpm", &x, &y);
	stc->coin = mlx_xpm_file_to_image(stc->mlx, "img_src/coin.xpm", &x, &y);
	stc->coin_1 = mlx_xpm_file_to_image(stc->mlx, "img_src/coin1.xpm", &x, &y);
	stc->coin_2 = mlx_xpm_file_to_image(stc->mlx, "img_src/coin2.xpm", &x, &y);
	stc->bg = mlx_xpm_file_to_image(stc->mlx, "img_src/space.xpm", &x, &y);
	stc->enemy = mlx_xpm_file_to_image(stc->mlx, "img_src/enemy.xpm", &x, &y);
	if (!stc->wall || !stc->player || !stc->out || !stc->collect || !stc->bg \
		|| !stc->enemy || !stc->coin_1 || !stc->coin_2 || !stc->coin)
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
			else if (stc->map[dx][dy] == '*')
				ft_paint(stc, stc->enemy, dy * 50, dx * 50);
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
	mlx_loop_hook(stc->mlx, animation, stc);
	mlx_hook(stc->win, 02, 0, key_hook, stc);
	mlx_hook(stc->win, 17, 0, ft_close, stc);
	mlx_loop(stc->mlx);
}
