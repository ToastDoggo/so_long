/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:00:53 by rehernan          #+#    #+#             */
/*   Updated: 2022/03/04 12:03:50 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_addr(unsigned long addr)
{
	int	len;

	if (!addr)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	len = ft_print_hex(addr, 'x');
	len += 2;
	return (len);
}

int	ft_print_out(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_num_len(unsigned long num, int base)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		len++;
		num = num / base;
	}
	return (len);
}

void	ft_put_unsigned_nbr(unsigned int i, int fd)
{
	if (i >= 10)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
	else
	{
		ft_putchar_fd(i + '0', fd);
	}
}
