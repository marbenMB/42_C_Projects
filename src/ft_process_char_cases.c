/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_char_cases.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:50:54 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/01/19 10:50:56 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	process_char(t_Check_FLAGS *flags)
{
	ft_putchar(va_arg(flags->args, int), flags);
}

void	process_str(t_Check_FLAGS *flags)
{
	char	*str;

	str = va_arg(flags->args, char *);
	if (!str)
		ft_putstr("(null)", flags);
	else
		ft_putstr(str, flags);
}
