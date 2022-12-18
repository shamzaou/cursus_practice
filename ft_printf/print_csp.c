/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:35:15 by shamzaou          #+#    #+#             */
/*   Updated: 2022/12/18 14:08:56 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* Prints a single character >> %c << */
void	print_char(va_list ap, int *len_ptr)
{
	char	c;

	c = va_arg(ap, int);
	*len_ptr += write(1, &c, 1);
}

/* Prints a string >> %s << */
void	print_str(va_list ap, int *len_ptr)
{
	char	*str;
	int		i;

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		*len_ptr += write(1, "(null)", 6);
		return ;
	}
	i = 0;
	while (str[i])
	{
		*len_ptr += write(1, &str[i], 1);
		i++;
	}
}

/* Prints the percent sign >> %% << */
void	print_percent(int *len_ptr)
{
	*len_ptr += ft_putchar('%');
}
