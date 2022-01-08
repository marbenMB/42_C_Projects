#include "../ft_printf.h"

int ft_putchar(char c)
{
    return (write(1, &c, 1));
}

void	ft_putnbr(long long n, char c)
{
	unsigned int	nb;

	if (c == 'u' && n < 0)
		nb = (unsigned)n;
	else if (n < 0)
	{
		ft_putchar_fd('-');
		nb = (unsigned int)(-1 * n);
	}
	else
		nb = (unsigned int)n;
	if (nb >= 10)
		ft_putnbr(nb / 10, c);
	ft_putchar(nb % 10 + 48);
}