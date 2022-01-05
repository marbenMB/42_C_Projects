#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
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

int	find_spec(char c)
{
	return (c == 'd'|| c == 'i'|| c == 'u'|| c == 's'
			|| c == 'c' || c == 'x' || c == 'X'|| c == 'p');
}

int ft_putchar(char c)
{
    return (write(1, &c, 1));
}