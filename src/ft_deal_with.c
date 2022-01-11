#include "../ft_printf.h"

void	deal_with_nor_flags(const char *format, Check_FLAGS *flags)
{
	while(!find_spec(*format) && *format)
	{
		if (*format == '+')
			flags->plus = 1;
		else if (*format == ' ')
			flags->space = 1;
		else if(*format == '#')
			flags->hash = 1;
		format++;
	}
}

void	deal_with_av_flags(const char *format, Check_FLAGS *flags)
{
	while (!find_spec(*format) && *format)
	{
		if (*format == '0')
		{
			flags->zero = 1;
			flags->width = ft_atoi(++format);
		}
		else if (*format == '-')
		{
			flags->mins = 1;
			flags->width = ft_atoi(++format);
		}
		else if (*format == '.')
		{
			flags->point = 1;
			flags->pres = ft_isdigit(*(++format));
			flags->v_pres = ft_atoi(format);
		}
		format++;
	}
}

void	deal_with_spec(char spec, Check_FLAGS *flags)
{
	flags->spec = spec;
	/* if (spec == 'd' || spec == 'i' || spec == 'u')
		ft_putnbr(va_arg(flags->args, long long), flags->spec);
	else if (spec == 'x' || spec == 'X')
		ft_puthex(va_arg(flags->args, long long), flags->spec);
	else if (spec == 'p')
		ft_puthex(va_arg(flags->args, long long), flags->spec); */
	
}