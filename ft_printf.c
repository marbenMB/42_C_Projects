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

void	deal_with_flags(const char *format, Check_FLAGS *flags)
{
	int	len;

	len = 0;
	while (!find_spec(*format))
	{
		if (*format == '0')
			flags->zero = 1;
		else if (*format == ' ')
			flags->space = 1;
		else if (*format == '#')
			flags->hash = 1;
		else if (*format == '+')
			flags->plus = 1;
		else if (*format == '-')
			flags->mins = 1;
		else if (*format == '.')
		{
			flags->point = 1;
			format++;
			if (ft_isdigit(*format))
			{
				flags->pres = 1;
				flags->v_pres = ft_atoi(format);
				format += ft_nb_len(flags->v_pres);
				continue;
			}
		}
		format++;
	}
}

int	ft_printf(const char *format, ...)
{
	int			len;
	Check_FLAGS	*flags;

	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			deal_with_flags(++format, flags);
		}
		else
			len += ft_putchar(*format);
		format++;
	}
	return (len);
}

#include <stdio.h>
int	main()
{  
	printf("\n%d", ft_printf("he--%"));
}
