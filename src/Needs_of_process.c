#include "../ft_printf.h"

void	process_ints_nor(int num, Check_FLAGS *flags)
{
	// Normal Flags without width :
	if (flags->plus && num >= 0)
		ft_putchar('+', flags);
	else if (flags->space && num >= 0)
		ft_putchar(' ', flags);
}

void	process_ints_av(int num, Check_FLAGS *flags)
{
	int	nbr_len;
	int	i;
	char c;

	nbr_len = ft_nbrlen(num);
	// Advanced Flags :	
	i = 0;
	if (flags->width > nbr_len && !flags->zero && !flags->mins)
		while (i++ < flags->width - flags->v_pres)
			ft_putchar(' ', flags);
	if (flags->v_pres && flags->v_pres > nbr_len)
		while (i++ < flags->v_pres - nbr_len)
			ft_putchar('0', flags);
	else if (!flags->v_pres)
		flags->v_pres = nbr_len;
	if (flags->width && flags->width > flags->v_pres)
	{
		if (flags->mins)
			i = 0;
		else if (flags->zero)
		{
			if (flags->point)
				c = ' ';
			else
				c = '0';
			i = 0;
			while (i++ < flags->width - nbr_len)
				ft_putchar(c, flags);
		}
	}
	ft_putnbr(num, flags);
	if (flags->mins && flags->width > flags->v_pres)
	{
		flags->width -= flags->v_pres;
		while (i++ < flags->width)
			ft_putchar(' ', flags);
	}
}