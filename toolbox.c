#include "ft_printf.h"

void    print_char(va_list ap, int *len_ptr)
{
    char c;

    c = va_arg(ap, char);
    *len_ptr += write(1, &c, 1);
}