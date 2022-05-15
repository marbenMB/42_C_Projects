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

//	***********		Structs		*********** :
typedef struct compo
{
	int	space;
	int	exit;
	int	collec;
	int	player;
}	t_comp;
//	***********		Functions	*********** :
//	***********	Errors : 
void	error_usage(void);
void	error_name(void);
void	error_file(void);
void	error_map(char **tab);

//	***********	Checks :
void	check_name(char *name);
void	check_wall(char **map);
void	check_components(char **map);
void	check_map(char *map);

//	***********	Parsing Utils :
void	free_tab(char **tab);
int		map_height(char **map);
char	*joining(char *str, char *line);
void	check_map_form(char *str, char *line, size_t len);
char	**get_map(int fd);
void	comp_init(t_comp *verf);
int		verf_comp(char c);
void	find_comp(char c, t_comp *verf);

#endif