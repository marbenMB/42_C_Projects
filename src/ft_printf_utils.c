/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:08:09 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/01/06 17:08:13 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	find_spec(char c)
{
	return (c == 'd'|| c == 'i'|| c == 'u'|| c == 's'
			|| c == 'c' || c == 'x' || c == 'X'|| c == 'p');
}

void	reset_data(Check_FLAGS *flags)
{
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->mins = 0;
	flags->zero = 0;
	flags->point = 0;
	flags->pres = 0;
	flags->v_pres = 0;
	flags->width = 0;
	flags->spec = 0;
}