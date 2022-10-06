/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:33:01 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/10/06 11:54:19 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	normilize_angle(double *angle)
{
	*angle = fmod(*angle, (2 * M_PI));
	if (*angle < 0)
		*angle = *angle + (2 * M_PI);
}

int	convert_todx(double a)
{
	return ((int)(a / TILE_SIZE));
}

int	tab_len(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		;
	return (i);
}

void	free_stc(t_data *data)
{
	free_tab(data->map);
	free(data->play);
	free(data->hooks);
	free(data->img);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
}