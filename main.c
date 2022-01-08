#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"


int main()
{   
    /* char c = 'c';
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
            c, s, p_d, p_d, n_d, n_d, p_d, p_d, p_d, &s); */
	int i = 3364;
	ft_puthex(i, 'X');
    return (0);
}