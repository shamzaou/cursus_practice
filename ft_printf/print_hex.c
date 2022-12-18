/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:32:47 by shamzaou          #+#    #+#             */
/*   Updated: 2022/12/18 14:15:32 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* Prints the void * pointer argument in hexadecimal format >> %p << */
void	print_ptr(va_list ap, int *len_ptr)
{
	unsigned long	ptr;

	ptr = (unsigned long)va_arg(ap, uintptr_t);
	*len_ptr += write(1, "0x", 2);
	if (ptr == 0)
		*len_ptr += write(1, "0", 1);
	else
		*len_ptr += to_hex(ptr, 'x');
}

/* Prints a number in hexadecimal format >> %x || %X << */
void	print_hex(char conversion_char, va_list ap, int *len_ptr)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	*len_ptr += to_hex(num, conversion_char);
}

/* Takes a decimal and converts it to hexadecimal */
int	to_hex(unsigned long ptr, char conversion)
{
	unsigned long	rem;
	char			c;
	static int		count;

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
		to_hex(ptr, conversion);
	write(1, &c, 1);
	count++;
	return (count);
}
