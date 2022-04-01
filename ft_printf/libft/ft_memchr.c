/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:47:10 by rehernan          #+#    #+#             */
/*   Updated: 2021/07/15 12:12:03 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** DESCRIPTION
*     The memchr() function locates the first occurrence of c
*	  (converted to an unsigned char) in string s.
* RETURN VALUES
*     The memchr() function returns a pointer to the byte located, 
*	  or NULL if no such byte exists within n bytes.
**/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (n > i)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
