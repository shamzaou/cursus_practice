/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:32:55 by shamzaou          #+#    #+#             */
/*   Updated: 2022/12/18 13:32:58 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
