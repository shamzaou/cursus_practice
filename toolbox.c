/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:35:15 by shamzaou          #+#    #+#             */
/*   Updated: 2022/12/12 13:48:39 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_char(va_list ap, int *len_ptr)
{
    char c;

    c = va_arg(ap, int);
    *len_ptr += write(1, &c, 1);
}

void    print_str(va_list ap, int *len_ptr)
{
    char    *str;
    int     i;

    str = va_arg(ap, char *);
    if (str == NULL)
    {
        *len_ptr += write(1, "(null)", 6);
        return;
    }
    i = 0;
    while (str[i])
    {
        *len_ptr += write(1, &str[i], 1);
        i++;
    }
}

void    print_ptr(va_list ap, int *len_ptr)
{
    unsigned long    ptr;

    ptr = (unsigned long) va_arg(ap, uintptr_t);
    *len_ptr += write(1, "0x", 2);
    if (ptr == 0)
        *len_ptr += write(1, "0", 1);
    else
        *len_ptr += to_hex(ptr, 'x');
}

int     to_hex(unsigned long ptr, char conversion)
{
    unsigned long    rem;
    char            c;
    static int      count;

    count = 0;
    rem = ptr % 16;
    if (rem <= 9)
        c = rem + '0';
    else if (rem > 9 && rem < 16 && conversion == 'X')
        c = (rem - 10) + 'A';
    else if (rem > 9 && rem < 16 && conversion == 'x')
        c = (rem - 10) + 'a';
    ptr = ptr / 16;
    if (ptr != 0)
        to_hex(ptr , conversion);
    write(1, &c, 1);
    count++;
    return(count);
}

void    print_int(va_list ap, int *len_ptr)
{
    int num;

    num = va_arg(ap, int);
    ft_putnbr(num, len_ptr);
}

int     ft_putchar(char c)
{
    return(write(1, &c, 1));
}

void     ft_putnbr(int nb, int *ptr)
{
    if (nb == -2147483648)
    {
        *ptr += write(1, "-2147483648", 11);
        return;
    }
	if (nb < 0)
    {
		*ptr += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
    {
		ft_putnbr(nb / 10, ptr);
		nb = nb % 10;
	}
	if (nb < 10)
        *ptr += ft_putchar(nb + 48);
}

void    print_uint(va_list ap, int *len_ptr)
{
    unsigned int    num;

    num = va_arg(ap, unsigned int);
    ft_putuint(num, len_ptr);
}

void    ft_putuint(unsigned int num, int *len_ptr)
{
    if (num >= 10)
        ft_putuint(num / 10, len_ptr);
    *len_ptr += ft_putchar(num % 10 + '0');
}

void    print_hex(char conversion_char, va_list ap, int *len_ptr)
{
    unsigned int num;

    num = va_arg(ap, unsigned int);
    *len_ptr += to_hex(num, conversion_char);
}

void    print_percent(int *len_ptr)
{
    *len_ptr += ft_putchar('%');
}