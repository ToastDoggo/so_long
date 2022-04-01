/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:55:41 by rehernan          #+#    #+#             */
/*   Updated: 2021/06/16 14:53:06 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *
 * The  memset()  function  fills  the  first  n  bytes of the memory area
 * pointed to by s with the constant byte c. 
 *
 * RETURN VALUE
 *	The memset() function returns a pointer to the memory area s.
 *
 **/

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ch;

	i = 0;
	ch = (char *)s;
	while (i < n)
	{
		ch[i] = c;
		i++;
	}
	return (s);
}
