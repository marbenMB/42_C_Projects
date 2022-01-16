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
// get the len that are printed :
	int	length;
}Check_FLAGS;
// main function :
int		ft_printf(const char *format, ...);
// libft functions :
	// ft_put :
void	ft_putchar(char c, Check_FLAGS *flags);
void	ft_putnbr(long long n, Check_FLAGS *flags);
void	ft_puthex(long long nbr, Check_FLAGS *flags);
void	ft_putstr(char *str, Check_FLAGS *flags);
	// auto_func :
size_t	ft_strlen(const char *s);
size_t	ft_nbrlen(long long num);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
// function utils :
int		find_spec(char c);
void	reset_data(Check_FLAGS *flags);
// src functions :
	// ft_deal_wiht :
void	deal_with_nor_flags(const char *format, Check_FLAGS *flags);
void	deal_with_av_flags(const char *format, Check_FLAGS *flags);
void	deal_with_spec(char format, Check_FLAGS *flags);
	// process_cases :
void	process_char(Check_FLAGS *flags);
void	process_str(Check_FLAGS *flags);
void	process_ints(Check_FLAGS *flags);
	// Needs of process :
void	process_ints_nor(int num, Check_FLAGS *flags);
void	process_ints_av(int num, Check_FLAGS *flags);
#endif
