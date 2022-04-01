/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:32:52 by rehernan          #+#    #+#             */
/*   Updated: 2021/06/26 20:32:31 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// DESCRIPTION
// 	The isascii() function shall test whether c is a 7-bit
// US-ASCII character code.
// 	The isascii() function is defined on all integer values.
// RETURN VALUE
// 	The isascii() function shall return non-zero if c is a 7-bit
// US-ASCII character code
// 	between 0 and octal 0177 inclusive; otherwise, it shall return 0.

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}
