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
}Check_FLAGS;

// functions utils :
int	find_spec(char c);
int ft_putchar(char c);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);
// functions :
int		ft_printf(const char *format, ...);
void	deal_with_flags(const char *format, Check_FLAGS *flags);
#endif
