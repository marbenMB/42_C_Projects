#include "../ft_printf.h"

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
