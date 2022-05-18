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
	free(stc->bg);
	free(stc->collect);
	free(stc->player);
	free(stc->wall);
	free(stc->out);
	free(stc->win);
	free_tab(stc->map);
}

void	stc_init(t_mlx *stc)
{
	stc->bg = NULL;
	stc->collect = NULL;
	stc->map = NULL;
	stc->mlx = NULL;
	stc->out = NULL;
	stc->player = NULL;
	stc->wall = NULL;
	stc->win = NULL;
	stc->count = 0;
}

int	key_hook(int key, t_mlx *stc)
{
	if (key == 53)
		ft_close(stc);
	if (key == 13 || key == 0 || key == 1 || key == 2)
		move_player(key, stc);
	return (0);
}

int	ft_close(t_mlx *stc)
{
	mlx_destroy_window(stc->mlx, stc->win);
	exit (EXIT_SUCCESS);
	return (0);
}
