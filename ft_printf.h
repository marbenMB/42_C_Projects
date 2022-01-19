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
	int		plus;
	int		space;
	int		hash;
	char	spec;
	va_list	args;
	int		length;
}t_Check_FLAGS;
// main function :
int		ft_printf(const char *format, ...);
void	ft_body(const char *format, t_Check_FLAGS *sub_spec);
// **** libft functions :
	// ft_put :
void	ft_putchar(char c, t_Check_FLAGS *flags);
void	ft_putnbr(long long n, t_Check_FLAGS *flags);
void	ft_puthex(unsigned long long nbr, t_Check_FLAGS *flags);
void	ft_putstr(char *str, t_Check_FLAGS *flags);
// **** function utils :
int		find_spec(char c);
void	reset_data(t_Check_FLAGS *flags);
// **** src functions :
	// ft_deal_wiht :
void	deal_with_nor_flags(const char *format, t_Check_FLAGS *flags);
void	deal_with_spec(char format, t_Check_FLAGS *flags);
	// process_cases :
void	process_char(t_Check_FLAGS *flags);
void	process_str(t_Check_FLAGS *flags);
void	process_ints(t_Check_FLAGS *flags);
void	process_unsigned(t_Check_FLAGS *flags);
void	process_hex(t_Check_FLAGS *flags);
void	process_addrs(t_Check_FLAGS *flags);
#endif
