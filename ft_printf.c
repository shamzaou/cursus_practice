/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:35:06 by shamzaou          #+#    #+#             */
/*   Updated: 2022/12/12 13:35:46 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{
    va_list ap;
    int     i;
    int     len;
    int     *len_ptr;

    va_start(ap, format);
    i = 0;
    len = 0;
    len_ptr = &len;
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            fchecker(format[i], ap, len_ptr);
        }
        else
            len += write(1, &format[i], 1);
        i++;
    }
    va_end(ap);
    return (len);
}

void    fchecker(char conversion_char, va_list ap, int  *len_ptr)
{
    if (conversion_char == 'c')
        print_char(ap, len_ptr);
    else if (conversion_char == 's')
        print_str(ap, len_ptr);
    else if (conversion_char == 'p')
        print_ptr(ap, len_ptr);
    else if (conversion_char == 'd' || conversion_char == 'i')
        print_int(ap, len_ptr);
    else if (conversion_char == 'u')
        print_uint(ap, len_ptr);
    else if (conversion_char == 'x' || conversion_char == 'X')
        print_hex(conversion_char, ap, len_ptr);
    else if (conversion_char == '%')
        print_percent(len_ptr);
}