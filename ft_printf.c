/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:58:23 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/01/06 16:59:57 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	Check_FLAGS	sub_spec;

	sub_spec.length = 0;
	reset_data(&sub_spec);
	va_start(sub_spec.args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				ft_putchar(*format++, &sub_spec);
				continue;
			}
			deal_with_nor_flags(format, &sub_spec);
			deal_with_av_flags(format, &sub_spec);
			while (!find_spec(*format))
				format++;
			deal_with_spec(*format, &sub_spec);
		}
		else
			ft_putchar(*format, &sub_spec);
		reset_data(&sub_spec);
		format++;
	}
	return (sub_spec.length);
}
