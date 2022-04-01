/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:43:03 by rehernan          #+#    #+#             */
/*   Updated: 2021/07/12 12:54:52 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The strrchr() function returns a pointer to the last occurrence
 * of the character c in the string s.
 * RETURN VALUE
 *      The strchr() and strrchr() functions return a pointer to the matched
 *	    character or NULL if the character  is  not  found.  The terminating
 *	    null byte is considered part of the string, so that if c is
 *      specified as '\0', these functions return a pointer to the terminator.
 **/

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + len);
	while (len >= 0)
	{
		if (s[len] == c)
			return ((char *)s + len);
		len --;
	}
	return (NULL);
}
