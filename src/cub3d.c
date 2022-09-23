/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:07:09 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/09/23 14:05:28 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		printf("\x1b[31m Error in arguments \033[0m\n");
		return (1);
	}
	else
    {
        init_data(&data);
		get_parced_map(&data, av[1]);
    }
	mlx_ptr_init(&data);
	drawing(&data);
	ft_mlx_hooking(&data);
	mlx_loop(data.mlx);
	return (0);
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->map = NULL;
	data->map_height = 0;
	data->map_width = 0;
	data->img = (t_img *)ft_calloc(1, sizeof(t_img));
	data->x_player = -1;
	data->y_player = -1;
}

void	mlx_ptr_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "+> MAR_BEN <+");
	data->img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
}

void	ft_mlx_hooking(t_data *data)
{
	mlx_hook(data->win, 02, 0, ft_key_press, data);
}
