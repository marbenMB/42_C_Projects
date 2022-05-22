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

void	ft_put_moves(t_mlx *stc, int n)
{
	char	*str;

	str = ft_itoa(n);
	mlx_string_put(stc->mlx, stc->win, 10, 12, 'R', "MOVES : ");
	mlx_string_put(stc->mlx, stc->win, 110, 12, 'R', str);
	free(str);
}

void	ft_swap(char *c1, char *c2)
{
	char	tmp;

	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

int	*get_pos(char **map, char c)
{
	int	*pos;

	pos = (int *)malloc(sizeof(int) * 2);
	pos[0] = -1;
	while (map[++pos[0]])
	{
		pos[1] = -1;
		while (map[pos[0]][++pos[1]])
			if (map[pos[0]][pos[1]] == c)
				return (pos);
	}
	return (0);
}

void	move_enemy(int key, t_mlx *stc)
{
	static int		*p;

	mlx_clear_window(stc->mlx, stc->win);
	p = get_pos(stc->map, '*');
	if (!p)
		return ;
	if (stc->map[p[0] - 1][p[1]] == '0' && key == 13)
		ft_swap(&stc->map[p[0] - 1][p[1]], &stc->map[p[0]][p[1]]);
	else if (stc->map[p[0] + 1][p[1]] == '0' && key == 1)
		ft_swap(&stc->map[p[0] + 1][p[1]], &stc->map[p[0]][p[1]]);
	else if (stc->map[p[0]][p[1] - 1] == '0' && key == 0)
		ft_swap(&stc->map[p[0]][p[1] - 1], &stc->map[p[0]][p[1]]);
	else if (stc->map[p[0]][p[1] + 1] == '0' && key == 2)
		ft_swap(&stc->map[p[0]][p[1] + 1], &stc->map[p[0]][p[1]]);
	free(p);
	ft_draw(stc);
}

void	move_player(int key, t_mlx *stc)
{
	int		*p;

	mlx_clear_window(stc->mlx, stc->win);
	p = get_pos(stc->map, 'P');
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
	ft_put_moves(stc, stc->count);
}
