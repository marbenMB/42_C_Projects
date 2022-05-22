/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:51:49 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/05/17 19:51:51 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_stc(t_mlx *stc)
{
	free_tab(stc->map);
}

void	play_animation(t_mlx *stc)
{
	mlx_clear_window(stc->mlx, stc->win);
	ft_draw(stc);
	ft_put_moves(stc, stc->count);
}

void	stc_init(t_mlx *stc)
{
	stc->bg = NULL;
	stc->collect = NULL;
	stc->coin = NULL;
	stc->coin_1 = NULL;
	stc->coin_2 = NULL;
	stc->map = NULL;
	stc->mlx = NULL;
	stc->out = NULL;
	stc->player = NULL;
	stc->wall = NULL;
	stc->win = NULL;
	stc->enemy = NULL;
	stc->count = 0;
}

int	key_hook(int key, t_mlx *stc)
{
	if (key == 53)
	{
		ft_putendl_fd("\033[33m ** END GAME **\033[0m", 1);
		ft_close(stc);
	}
	if (key == 13 || key == 0 || key == 1 || key == 2)
	{
		move_enemy(key, stc);
		move_player(key, stc);
	}
	return (0);
}

int	ft_close(t_mlx *stc)
{
	mlx_destroy_window(stc->mlx, stc->win);
	free_stc(stc);
	exit (EXIT_SUCCESS);
	return (0);
}
