/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:58:01 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/01/11 22:58:03 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "ft_printf.h"

/* ------------------------------------------------------------------------- */
						/* TESTING THE STRUCTUR */
/* ------------------------------------------------------------------------- */

/* int main(int ac, char **av)
{
	int i = 1;
	Check_FLAGS flags;
	char	*p;
	ac = 2;
	//yav[1] = "hello world %+#x%-4.2s yes it is in the table %.s";
	p = av[1];
	if (ac != 2)
		return (0);
	reset_data(&flags);
	while (*p)
	{
		if (*p == '%')
		{
			p++;
			deal_with_nor_flags(p, &flags);
			deal_with_av_flags(p, &flags);
			while (!find_spec(*p))
				p++;
			deal_with_spec(*p, &flags);
			printf("\033[0;32m/ ------------------------------	------------------------------ \\ \n\t\t\t TESTING NORMAL FLAGS : %d\n\\ ------------------------------	------------------------------ /\n",i);
			printf(" \033[0;31m\t-\tplus = %d \n \t-\tspace = %d \n \t-\thash = %d\n", flags.plus, flags.space, flags.hash);
			printf("\033[0;32m/ ------------------------------	------------------------------ \\ \n\t\t\t TESTING ADVANC FLAGS : %d\n\\ ------------------------------	------------------------------ /\n",i);
			printf(" \033[0;31m\t-\tpoint = %d \n \t-\tzero = %d \n \t-\tmins = %d\n \t-\tpres = %d\n", flags.point, flags.zero, flags.mins, flags.pres);
			printf("\033[0;32m/ ------------------------------	------------------------------ \\ \n\t\t\t TESTING FLAGS VALUES : %d\n\\ ------------------------------	------------------------------ /\n",i);
			printf(" \033[0;31m\t-\tv_pres = %d \n \t-\twidht = %d \n \t-\tspec = %c\n", flags.v_pres, flags.width, flags.spec);
			i++;
		}
		reset_data(&flags);
		p++;
	}
} */


/* ------------------------------------------------------------------------- */
						/* TESTING THE FUNCTIONS */
/* ------------------------------------------------------------------------- */


int	main()
{
	Check_FLAGS test;
	test.spec = 'x';
	test.mins = 1;
	test.width = 4;
	//test.length = 0;

	//process_char(&test);
	printf("\n%s\n", "hello");
}



/* ------------------------------------------------------------------------- */
						/* TESTING REALL PRINTF */
/* ------------------------------------------------------------------------- */

/* int main()
{   
     char c = 'c';
    char *s = "yes";
    int p_d = 4;
    int n_d = -4;

    printf("Testing FLAGS : \n \
            c   = .%03c. \n \
            s   = .%03s. \n \
            p_d = .%03d.  p_i = .%03i. \n \
            n_d = .%03d.  n_i = .%03i. \n \
            u   = .%03u. \n \
            x   = .%03x.  X   = .%03X. \n \
            p   = .%03p.", \
            c, s, p_d, p_d, n_d, n_d, p_d, p_d, p_d, &s);
	int i = 3364;
	ft_puthex(i, 'X');
    return (0);
} */


/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */

/* void	func(int n, ...)
{
	int i = 0;
	int integer;
	Check_FLAGS flags;
	flags.spec = 'u';
	va_list args;

	va_start(args, n);
	while (i < n)
	{
		integer = va_arg(args, long long);
		printf("Printf : %d\n", integer);
		puts("Putnbr :");
		ft_putnbr(integer, &flags);
		puts("\n----------");
		i++;
	}
}

int main()
{
	func(4, -1, 1, INT64_MIN ,12);
} */