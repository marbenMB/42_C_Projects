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

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}


int	find_spec(char c)
{
	return (c == 'd'|| c == 'i'|| c == 'u'|| c == 's'
			|| c == 'c' || c == 'x' || c == 'X'|| c == 'p');
}

int ft_putchar(char c)
{
    return (write(1, &c, 1));
}

