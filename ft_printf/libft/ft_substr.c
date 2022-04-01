/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 19:36:08 by rehernan          #+#    #+#             */
/*   Updated: 2021/08/13 21:04:42 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* Allocates (with malloc(3)) and returns a substring
* from the string ’s’.
* The substring begins at index ’start’ and is of
* maximum size ’len’.
**/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	length;

	if (s == NULL)
		return (NULL);
	i = 0;
	length = ft_strlen(s);
	if (start >= length || !s)
		len = 0;
	else if (length < (start + len))
		len = length - start;
	dest = malloc(len + 1);
	if (dest != NULL)
	{
		while (i < len && s[i])
		{
			dest[i] = s[start + i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
