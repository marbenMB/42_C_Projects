/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:56:24 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/01/11 22:56:28 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

size_t	ft_nbrlen(int num)
{
	size_t	i;

	if (!num)
		return(1);
	else if (num < 0)
		num = num * -1;
	i = 0;
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

int	ft_isdigit(int c)
{
	return(c >= 48 && c <= 57);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	signe;

	num = 0;
	signe = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -signe;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		num = num * 10 + *str - 48;
		str++;
	}
	return (num * signe);
}
