/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_cases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:50:54 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/01/19 10:50:56 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	process_char(Check_FLAGS *flags)
{
	int	i;

	if (flags->width && !flags->mins)
		while (flags->width-- > 1)
			ft_putchar(' ', flags);
	ft_putchar(va_arg(flags->args, int), flags);
	if (flags->mins == 1)
	{
		i = 1;
		while (i++ < flags->width)
			ft_putchar(' ', flags);
	}
}

void	process_str(Check_FLAGS *flags)
{
	char	*str;
	int		i;
	int		str_len;

	str = va_arg(flags->args, char *);	/* 	str = NULL; */
	if (!str)
		str = "(null)"; 	/* !!!! CHEKC THIS AGAIN AFTER THE AV TESTING */
	str_len = ft_strlen(str);
	if (!flags->point && !flags->pres && !flags->v_pres)
		flags->v_pres = str_len;
	else if (flags->v_pres && flags->v_pres < str_len)
		str_len = flags->v_pres;
	if (!flags->mins && flags->width)
	{
			i = 0;
			while (i++ < flags->width - str_len)
				ft_putchar(' ', flags);
	}
	ft_putstr(str, flags);
	if (flags->mins && flags->width)
	{
			i = 0;
			while (i++ < flags->width - str_len)
				ft_putchar(' ', flags);
	}
}

void	process_ints(Check_FLAGS *flags)
{
	long long		num;
	char	c;
	int		i;
	int		nbr_len;

	num = va_arg(flags->args, int);
	nbr_len = ft_nbrlen(num);
	/* // Normal Flags without width : ********************************************************** */
	if (flags->plus && num >= 0)
		ft_putchar('+', flags);
	else if (flags->space && num >= 0)
		ft_putchar(' ', flags);
	/* // Advanced Flags : *********************************************************************  */
	if (!(flags->point && !flags->v_pres && num == 0))
	{
		i = 0;
		if (flags->point && num < 0)
			nbr_len--;
		if (!flags->v_pres || flags->v_pres < nbr_len)
			flags->v_pres = nbr_len;
		if (flags->width > nbr_len && !flags->zero && !flags->mins)
			while (i++ < flags->width - flags->v_pres)
				ft_putchar(' ', flags);
		if (num < 0)
			ft_putchar('-', flags);
		if (flags->v_pres && flags->v_pres > nbr_len)
		{
			while (i++ < flags->v_pres - nbr_len)
				ft_putchar('0', flags);
		}
/* 		else if (!flags->v_pres)
			flags->v_pres = nbr_len; */
		if (flags->width && flags->width > flags->v_pres)
		{
			if (flags->zero)
			{
				if (flags->point)
					c = ' ';
				else
					c = '0';
				i = 0;
				while (i++ < flags->width - nbr_len - flags->v_pres)
					ft_putchar(c, flags);
			}
		}
		if (num < 0)
			num = num * -1;
		ft_putnbr(num, flags);
	}
	i = 0;
	if (flags->mins && flags->width > flags->v_pres)
	{
		flags->width -= flags->v_pres;
		while (i++ < flags->width)
			ft_putchar(' ', flags);
	}
}
