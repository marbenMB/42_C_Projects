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
	char	*str;
	int		i;
	int		str_len;

	str = va_arg(flags->args, char *);	/* 	str = NULL; */
	if (!str)
		str = "(null)"; 	/* !!!! CHEKC THIS AGAIN AFTER THE AV TESTING */
	str_len = ft_strlen(str);
	if (!flags->pres || !flags->v_pres)
		flags->v_pres = str_len;
	else if (flags->v_pres)
		str_len = flags->v_pres;
	ft_putstr(str, flags);
	if (flags->mins)
	{
			i = 0;
			while (i++ < flags->width - str_len)
				ft_putchar(' ', flags);
	}	
}