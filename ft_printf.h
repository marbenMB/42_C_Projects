/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:07:06 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/01/06 17:07:30 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// includes :
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

// definitions :
# define LOW_BASE "0123456789abcdef"
# define UP_BASE "0123456789ABCDEF"

typedef struct flags
{
// Check the existence : 0 || 1
	// flags without width
	int plus;
	int space;
	int hash;
	// flags with width
	int	zero;
	int	mins;
	int point;
// get the values
	int	pres; // if there is a v_pres == 1 , if not == 0
	int v_pres;
	int width;
// get the specifier
	char spec;
// get the args 
	va_list	args;
}Check_FLAGS;
// main function :
int		ft_printf(const char *format, ...);
// libft functions :
int ft_putchar(char c);
void	ft_putnbr(long long n, char c);
void	ft_puthex(long long nbr, char c);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);
// src functions :
void	deal_with_nor_flags(const char *format, Check_FLAGS *flags);
void	deal_with_av_flags(const char *format, Check_FLAGS *flags);
void	deal_with_spec(char format, Check_FLAGS *flags);
// function utils :
int	find_spec(char c);
void	reset_data(Check_FLAGS *flags);
#endif
