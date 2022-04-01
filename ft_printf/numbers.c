/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:16:06 by rehernan          #+#    #+#             */
/*   Updated: 2022/03/04 11:59:16 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	hex_check(int hex, char x)
{
	char	*low;
	char	*upp;

	upp = "ABCDEF";
	low = "abcdef";
	hex = hex - 10;
	if (x == 'x')
		return (low[hex]);
	else
		return (upp[hex]);
}

int	convert_hex(int len, unsigned long hex, const char format, char *temp_hex)
{
	int	remainder;

	len--;
	while (len >= 0)
	{
		remainder = hex % 16;
		if (remainder > 9)
			remainder = hex_check(remainder, format);
		else
			remainder = remainder + '0';
		temp_hex[len] = remainder;
		hex = hex / 16;
		len--;
	}
	return (len);
}

int	ft_print_hex(unsigned long hex, const char format)
{
	int				len;
	char			*temp_hex;

	if (hex == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	len = ft_num_len(hex, 16);
	temp_hex = malloc(len + 1);
	if (!temp_hex)
		return (0);
	temp_hex[len] = '\0';
	convert_hex(len, hex, format, temp_hex);
	len = ft_print_out(temp_hex);
	free(temp_hex);
	return (len);
}

int	ft_print_digit(int d)
{
	int		len;
	long	num;

	len = 0;
	if (d > 0)
		len = ft_num_len(d, 10);
	else if (d == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		num = d;
		num *= -1;
		len = ft_num_len(num, 10) + 1;
	}
	ft_putnbr_fd(d, 1);
	return (len);
}

int	ft_print_unsigned(int d)
{
	int				len;
	unsigned int	num;

	len = 0;
	num = 0;
	if (d == 0)
		len = ft_print_digit(d);
	else if (d > 0)
		len = ft_print_digit(d);
	else
	{
		num = d;
		len = ft_num_len(num, 10);
		ft_put_unsigned_nbr(num, 1);
		return (len);
	}
	return (len);
}
