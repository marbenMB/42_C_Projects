/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:28:10 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/05/15 19:28:12 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	comp_init(t_comp *verf)
{
	verf->collec = 0;
	verf->exit = 0;
	verf->player = 0;
	verf->space = 0;
}

int	verf_comp(char c)
{
	return (c == 'E' || c == 'C' || c == 'P' \
			|| c == '0' || c == '1' || c == '*');
}

void	find_comp(char c, t_comp *verf)
{
	if (c == 'E')
		verf->exit = 1;
	else if (c == 'C')
		verf->collec++;
	else if (c == 'P')
		verf->player++;
	else if (c == '0')
		verf->space = 1;
}
