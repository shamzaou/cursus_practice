#include "ft_printf.h"

void    print_char(va_list ap, int *len_ptr)
{
    char c;

    c = va_arg(ap, char);
    *len_ptr += write(1, &c, 1);
}

void    print_str(va_list ap, int *len_ptr)
{
    char    *str;
    int     i;

    str = va_arg(ap, char *);
    i = 0;
    while (str[i])
    {
        *len_ptr += write(1, &str[i], 1);
        i++;
    }
}

void    print_ptr(va_list ap, int *len_ptr)
{
    
}