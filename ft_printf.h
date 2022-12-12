#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int     ft_printf(const char *format, ...);
void    fchecker(char conversion_char, va_list ap, int  *len_ptr)

void    print_char(va_list ap, int *len_ptr);
void    print_str(va_list ap, int *len_ptr);
void    print_ptr(va_list ap, int *len_ptr);
void    print_int(va_list ap, int *len_ptr);
void    print_uint(va_list ap, int *len_ptr);
void    print_hex(char conversion_char, va_list ap, int *len_ptr);
void    print_percent(int *len_ptr);

int     ft_putchar(char c);
void    ft_putnbr(int nb, int *ptr);
void    ft_putuint(unsigned int num, int *len_ptr);
int     to_hex(unsigned int ptr, char conversion);

#endif