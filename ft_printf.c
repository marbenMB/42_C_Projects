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
	// int			len;
	Check_FLAGS	sub_spec;

	// len = 0;
	reset_data(&sub_spec);
	va_start(sub_spec.args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			deal_with_nor_flags(format, &sub_spec);
			deal_with_av_flags(format, &sub_spec);
			while (!find_spec(*format))
				format++;
			deal_with_spec(*format, &sub_spec);
		}
		else
			ft_putchar(*format);
		reset_data(&sub_spec);
		format++;
	}
	//return (len);
}

#include <stdio.h>
int	main()
{  
	printf("\n%d", ft_printf("he--%"));
}
