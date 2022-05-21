/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:42:32 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/05/18 18:42:44 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_mlx *stc, int *p)
{
	if (stc->map[p[0] - 1][p[1]] == '0')
	{
		ft_swap(&stc->map[p[0] - 1][p[1]], &stc->map[p[0]][p[1]]);
		ft_put_moves(stc->count++);
	}
	if (stc->map[p[0] - 1][p[1]] == 'C')
	{
		stc->map[p[0] - 1][p[1]] = 'P';
		stc->map[p[0]][p[1]] = '0';
		stc->verf.collec--;
		ft_put_moves(stc->count++);
	}
	if (stc->map[p[0] - 1][p[1]] == 'E' && !stc->verf.collec)
	{	
		ft_put_moves(stc->count++);
		ft_putendl_fd("\033[32m ** YOU WON **\033[0m", 1);
		ft_close(stc);
	}
}

void	move_down(t_mlx *stc, int *p)
{
	if (stc->map[p[0] + 1][p[1]] == '0')
	{
		ft_swap(&stc->map[p[0] + 1][p[1]], &stc->map[p[0]][p[1]]);
		ft_put_moves(stc->count++);
	}
	if (stc->map[p[0] + 1][p[1]] == 'C')
	{
		stc->map[p[0] + 1][p[1]] = 'P';
		stc->map[p[0]][p[1]] = '0';
		stc->verf.collec--;
		ft_put_moves(stc->count++);
	}
	if (stc->map[p[0] + 1][p[1]] == 'E' && !stc->verf.collec)
	{
		ft_put_moves(stc->count++);
		ft_putendl_fd("\033[32m ** YOU WON **\033[0m", 1);
		ft_close(stc);
	}
}

void	move_right(t_mlx *stc, int *p)
{
	if (stc->map[p[0]][p[1] + 1] == '0')
	{
		ft_swap(&stc->map[p[0]][p[1] + 1], &stc->map[p[0]][p[1]]);
		ft_put_moves(stc->count++);
	}
	if (stc->map[p[0]][p[1] + 1] == 'C')
	{
		stc->map[p[0]][p[1] + 1] = 'P';
		stc->map[p[0]][p[1]] = '0';
		stc->verf.collec--;
		ft_put_moves(stc->count++);
	}
	if (stc->map[p[0]][p[1] + 1] == 'E' && !stc->verf.collec)
	{
		ft_put_moves(stc->count++);
		ft_putendl_fd("\033[32m ** YOU WON **\033[0m", 1);
		ft_close(stc);
	}
}

void	move_left(t_mlx *stc, int *p)
{
	if (stc->map[p[0]][p[1] - 1] == '0')
	{
		ft_swap(&stc->map[p[0]][p[1] - 1], &stc->map[p[0]][p[1]]);
		ft_put_moves(stc->count++);
	}
	if (stc->map[p[0]][p[1] - 1] == 'C')
	{
		stc->map[p[0]][p[1] - 1] = 'P';
		stc->map[p[0]][p[1]] = '0';
		stc->verf.collec--;
		ft_put_moves(stc->count++);
	}
	if (stc->map[p[0]][p[1] - 1] == 'E' && !stc->verf.collec)
	{
		ft_put_moves(stc->count++);
		ft_putendl_fd("\033[32m ** YOU WON **\033[0m", 1);
		ft_close(stc);
	}
}
