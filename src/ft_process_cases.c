#include "../ft_printf.h"

void	process_char(Check_FLAGS *flags)
{
	int	i;

	ft_putchar(va_arg(flags->args, int), flags);
	if (flags->mins == 1)
	{
		i = 1;
		while (i++ < flags->width)
			ft_putchar(' ', flags);
	}
}

void	process_str(Check_FLAGS *flags)
{
	char *str;

	str = va_arg(flags->args, char *);
	if 
}