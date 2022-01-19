/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:56:43 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/01/11 22:56:45 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	deal_with_nor_flags(const char *format, t_Check_FLAGS *flags)
{
	while (!find_spec(*format) && *format)
	{
		if (*format == '+')
			flags->plus = 1;
		else if (*format == ' ')
			flags->space = 1;
		else if (*format == '#')
			flags->hash = 1;
		format++;
	}
}

void	deal_with_spec(char spec, t_Check_FLAGS *flags)
{
	flags->spec = spec;
	if (spec == 'c')
		process_char(flags);
	else if (spec == 's')
		process_str(flags);
	else if (spec == 'd' || spec == 'i')
		process_ints(flags);
	else if (spec == 'u')
		process_unsigned(flags);
	else if (spec == 'x' || spec == 'X')
		process_hex(flags);
	else if (spec == 'p')
		process_addrs(flags);
}
