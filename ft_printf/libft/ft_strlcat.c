/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:24:40 by rehernan          #+#    #+#             */
/*   Updated: 2021/08/12 17:43:45 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	longer;
	size_t	reserve;
	size_t	i;

	longer = ft_strlen(src);
	reserve = ft_strlen(dst);
	i = 0;
	if (size <= reserve)
		return (size + longer);
	else if (size > 0)
	{
		while (i + reserve < size - 1 && src[i] != '\0')
		{
			dst[reserve + i] = src[i];
			i++;
		}
		dst[reserve + i] = '\0';
	}
	return (longer + reserve);
}
