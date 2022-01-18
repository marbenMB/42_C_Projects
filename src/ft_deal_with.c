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

void	deal_with_nor_flags(const char *format, Check_FLAGS *flags)
{
	while(!find_spec(*format) && *format)
	{
		if (*format == '+')
			flags->plus = 1;
		else if (*format == ' ')
			flags->space = 1;
		else if(*format == '#')
			flags->hash = 1;
		format++;
	}
}

void	deal_with_av_flags(const char *format, Check_FLAGS *flags)
{
	if (*format > '0' && *format <= '9')
	{
			flags->width = ft_atoi(format);
			format += ft_nbrlen(flags->width);
	}
	if (*format == '0')
		{
			flags->zero = 1;
			while (*format == '0')
				format++;
			if (ft_isdigit(*(format)))
				flags->width = ft_atoi(format);
		}
	while (!find_spec(*format) && *format)
	{
		if (*format == '-')
		{
			flags->mins = 1;
			while (*format == '-')
				format++;
			if (ft_isdigit(*(format)))
				flags->width = ft_atoi(format);
		}
		if (*format == '.')
		{
			flags->point = 1;
			while (*format == '.')
				format++;
			if ((flags->pres = ft_isdigit(*(format))))
				flags->v_pres = ft_atoi(format);
		}
		if (*format)
			format++;
	}
}

void	deal_with_spec(char spec, Check_FLAGS *flags)
{
	flags->spec = spec;
	if (spec == 'c')
		process_char(flags);
	else if (spec == 's')
		process_str(flags);
	else if (spec == 'd' || spec == 'i')
		process_ints(flags);
	else if (spec == 'u')
		ft_putnbr(va_arg(flags->args, unsigned int), flags);
	else if (spec == 'x' || spec == 'X')
		ft_puthex(va_arg(flags->args, long long), flags);
	else if (spec == 'p')
		ft_puthex(va_arg(flags->args, unsigned long long), flags);	
}
