/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:22:07 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/05/12 17:22:09 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//	***********		Includes	*********** :
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <mlx.h>

//	***********		Structs		*********** :
typedef struct compo
{
	int	space;
	int	exit;
	int	collec;
	int	player;
}	t_comp;

typedef struct s_mlx
{
	char	**map;
	t_comp	verf;
	void	*mlx;
	void	*win;
	void	*wall;
	void	*player;
	void	*bg;
	void	*collect;
	void	*out;
	int		count;
}	t_mlx;

//	***********		Functions	*********** :
//	***********	Errors : 
void	error_usage(void);
void	error_name(void);
void	error_file(void);
void	error_map(char **tab);

//	***********	Checks :
void	check_name(char *name);
void	check_wall(char **map);
void	check_elem(char **map, t_comp *verf);
void	check_components(char **map, t_comp *verf);
char	**check_map(char *map, t_comp *verf);

//	***********	Parsing Utils :
void	free_tab(char **tab);
int		map_height(char **map);
char	*joining(char *str, char *line, char *temp, size_t len);
void	check_map_form(char *str, char *line, size_t len);
char	**get_map(int fd);
void	comp_init(t_comp *verf);
int		verf_comp(char c);
void	find_comp(char c, t_comp *verf);

//	***********	Drawing Funcitons :
void	open_wind(t_mlx *stc);
void	create_components(t_mlx *stc);
void	ft_paint(t_mlx *stc, void *img, int dy, int dx);
void	ft_draw(t_mlx *stc);

//	***********	Draw Utils :
void	free_stc(t_mlx *stc);
void	stc_init(t_mlx *stc);
int		key_hook(int key, t_mlx *stc);
int		ft_close(t_mlx *stc);

//	***********	Play Utils :
void	ft_swap(char *c1, char *c2);
int		*get_pos(char **map);
void	move_player(int key, t_mlx *stc);

//	***********	Play Utils :
void	ft_put_moves(int n);
void	move_up(t_mlx *stc, int *p);
void	move_down(t_mlx *stc, int *p);
void	move_right(t_mlx *stc, int *p);
void	move_left(t_mlx *stc, int *p);

#endif