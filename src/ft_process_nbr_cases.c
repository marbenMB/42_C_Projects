/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_nbr_cases.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:51:52 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/01/19 21:51:55 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	process_ints(t_Check_FLAGS *flags)
{
	long long	num;

	num = va_arg(flags->args, int);
	if (flags->plus && num >= 0)
		ft_putchar('+', flags);
	else if (flags->space && num >= 0)
		ft_putchar(' ', flags);
	ft_putnbr(num, flags);
}

void	process_unsigned(t_Check_FLAGS *flags)
{
	unsigned int	num;

	num = va_arg(flags->args, unsigned int);
	ft_putnbr(num, flags);
}

void	process_hex(t_Check_FLAGS *flags)
{
	long long	nbr;

	nbr = va_arg(flags->args, long long);
	if (flags->hash && nbr)
	{
		if (flags->spec == 'x')
			ft_putstr("0x", flags);
		else if (flags->spec == 'X')
			ft_putstr("0X", flags);
	}
	ft_puthex(nbr, flags);
}

void	process_addrs(t_Check_FLAGS *flags)
{
	ft_putstr("0x", flags);
	ft_puthex(va_arg(flags->args, long long), flags);
}
