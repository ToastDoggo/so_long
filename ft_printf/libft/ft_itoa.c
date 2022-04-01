/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:56:39 by rehernan          #+#    #+#             */
/*   Updated: 2021/08/14 16:20:08 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(long num)
{
	int	size;

	size = 0;
	if (num <= 0)
		size++;
	while (num)
	{
		num /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	long	nb;

	nb = n;
	len = ft_size(nb);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	else if (nb == 0)
		result[0] = '0';
	result[len] = '\0';
	while (nb)
	{
		len--;
		result[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (result);
}
