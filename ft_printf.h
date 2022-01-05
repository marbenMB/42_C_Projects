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
	int	mins;
	int plus;
	int	zero;
	int space;
	int hash;
	int point;
	int	pres;
	int v_pres;
	int width;
}Check_FLAGS;

// functions utils :
int		find_spec(char c);
int 	ft_putchar(char c);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);
// functions :
int 	ft_printf(const char *format, ...);
void	deal_with_flags(const char *format, Check_FLAGS *flags);
#endif