/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:12:09 by rehernan          #+#    #+#             */
/*   Updated: 2021/06/16 14:53:22 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * 
 * The  memcmp()  function compares the first n bytes (each interpreted as
 * unsigned char) of the memory areas s1 and s2.
 *
 * RETURN VALUE
 * 	The memcmp() function returns  an  integer  less  than,  equal  to,  or
 * 	greater than zero if the first n bytes of s1 is found, respectively, to
 * 	be less than, to match, or be greater than the first n bytes of s2.
 *
 *  For a nonzero return value, the sign is determined by the sign  of  the
 *  difference  between  the  first  pair of bytes (interpreted as unsigned
 *  char) that differ in s1 and s2.
 * 
 **/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (i < n)
	{
		if (c1[i] == c2[i])
			i++;
		else
			return (c1[i] - c2[i]);
	}
	return (0);
}
