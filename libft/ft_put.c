/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:56:33 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/01/11 22:56:35 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_putchar(char c, Check_FLAGS *flags)
{
    flags->length += write(1, &c, 1);
}

void	ft_putnbr(long long n, Check_FLAGS *flags)
{
	unsigned int	nb;

	/* if (flags->spec == 'u' && n < 0)
		nb = (unsigned)n; */
	/* else */ if (n < 0)
	{
		ft_putchar('-', flags);
		nb = (unsigned int)(-1 * n);
	}
	else
		nb = (unsigned int)n;
	if (nb >= 10)
		ft_putnbr(nb / 10, flags);
	ft_putchar(nb % 10 + 48, flags);
}

void	ft_puthex(long long nbr, Check_FLAGS *flags)
{
	char *base;

	if (flags->spec == 'x' || flags->spec == 'p')
		base = LOW_BASE;
	else if (flags->spec == 'X')
		base = UP_BASE;
	if (flags->spec == 'p')
		ft_putstr("0x", flags);
	if (nbr < 0)
			nbr = (unsigned int)nbr;
	if (nbr / 16 != 0 )
	{
		ft_puthex(nbr / 16, flags);
		ft_putchar(base[nbr % 16], flags);
	}
	else if (nbr / 16 == 0)
		ft_putchar(base[nbr], flags);
}

void	ft_putstr(char *str, Check_FLAGS *flags)
{
	int	i;

	i = 0;
	/* if (flags->v_pres == 0)
		flags->v_pres = ft_strlen(str); */
	while (*str && i++ < flags->v_pres)
	{
		ft_putchar(*str, flags);
		str++;
	}
}
