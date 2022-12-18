/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:35:06 by shamzaou          #+#    #+#             */
/*   Updated: 2022/12/18 14:06:40 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/**
 * @brief Exploring Variadic functions implementing printf.
 * Variadic functions are functions that can take a variable
 * number of arguments. In C programming, a variadic function
 * adds flexibility to the program. It takes one fixed argument
 * and then any number of arguments can be passed. The variadic
 * function consists of at least one fixed variable and then an
 * ellipsis(…) as the last parameter.
 * 
 * @param format format will be the pointer to the last fixed argument
 * in the variadic function, this will enable access to vaiadic
 * function arguments.
 * @param ... The variadic function arguments.
 * @return int The ft_printf function will print to the standard
 * output the passed arguments. The return value wil be the sum
 * of the successfully   printed characters.
 */
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;
	int		*len_ptr;

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

/* Everytime the percent % character is encountered this function
* is called to check the following character and identify the type of
* the wanted conversion.*/
void	fchecker(char conversion_char, va_list ap, int *len_ptr)
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
