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
}

int	key_hook(int key, t_mlx *stc)
{
	if (key == 53)
	{
		mlx_destroy_window(stc->mlx, stc->win);
		exit (EXIT_SUCCESS);
	}
	if (key == 13 || key == 0 || key == 1 || key == 2)
		move_player(key, stc);
	return (0);
}

void	move_player(int key, t_mlx *stc)
{
	printf("%d\n", key);
	printf("%s\n", stc->map[0]);
}