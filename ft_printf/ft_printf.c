/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:14:38 by rehernan          #+#    #+#             */
/*   Updated: 2022/03/04 12:14:51 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	checker(char format)
{
	int	buli;

	buli = 0;
	if (format == 'c' || \
		format == 'd' || \
		format == 'i' || \
		format == 'p' || \
		format == 's' || \
		format == '%' || \
		format == 'u' || \
		format == 'x' || \
		format == 'X')
		buli = 1;
	return (buli);
}

int	handleformat(const char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_printf_char(va_arg(args, int));
	else if (format == 'd' || format == 'i')
		len = ft_print_digit(va_arg(args, int));
	else if (format == 'p')
		len = ft_print_addr(va_arg(args, unsigned long));
	else if (format == 'x' || format == 'X')
		len = ft_print_hex((unsigned long)va_arg(args, unsigned int), format);
	else if (format == 's')
		len = ft_print_out(va_arg(args, char *));
	else if (format == 'u')
		len = ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == '%')
	{
		ft_putchar_fd('%', 1);
		len = 1;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	va_list	args;

	va_start(args, format);
	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ret += handleformat(format[i + 1], args);
			i++;
		}
		else
			ret += write (1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (ret);
}
