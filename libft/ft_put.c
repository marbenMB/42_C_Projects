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
		ft_putchar('-');
		nb = (unsigned int)(-1 * n);
	}
	else
		nb = (unsigned int)n;
	if (nb >= 10)
		ft_putnbr(nb / 10, c);
	ft_putchar(nb % 10 + 48);
}

void	ft_puthex(long long nbr, char c)
{
	char *base;

	if (c == 'x')
		base = LOW_BASE;
	else if (c == 'X')
		base = UP_BASE;
	if (nbr / 16 != 0 )
	{
		ft_puthex(nbr / 16, c);
		ft_putchar(base[nbr % 16]);
	}
	else if (nbr / 16 == 0)
		ft_putchar(base[nbr]);
}