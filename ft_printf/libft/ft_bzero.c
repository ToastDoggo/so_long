/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:15:17 by toasty            #+#    #+#             */
/*   Updated: 2021/06/16 16:35:40 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* The  bzero()  function  erases  the  data  in the n bytes of the memory
*       starting at the location pointed to by s, by writing zeros (bytes  con‐
*       taining '\0') to that area.
*
*RETURN VALUE
*       None.
**/

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*c;

	i = 0;
	c = (char *)s;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}
