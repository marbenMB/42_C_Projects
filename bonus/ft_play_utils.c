/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:09:06 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/05/18 18:09:07 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_moves(int n)
{
	ft_putnbr_fd(n, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_swap(char *c1, char *c2)
{
	char	tmp;

	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

int	*get_pos(char **map)
{
	int	*pos;

	pos = (int *)malloc(sizeof(int) * 2);
	pos[0] = -1;
	while (map[++pos[0]])
	{
		pos[1] = -1;
		while (map[pos[0]][++pos[1]])
			if (map[pos[0]][pos[1]] == 'P')
				return (pos);
	}
	return (0);
}

void	move_player(int key, t_mlx *stc)
{
	int		*p;

	mlx_clear_window(stc->mlx, stc->win);
	p = get_pos(stc->map);
	if (key == 13)
		move_up(stc, p);
	if (key == 1)
		move_down(stc, p);
	if (key == 2)
		move_right(stc, p);
	if (key == 0)
		move_left(stc, p);
	free(p);
	ft_draw(stc);
}
