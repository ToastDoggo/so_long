/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 21:36:49 by rehernan          #+#    #+#             */
/*   Updated: 2021/07/09 21:57:28 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** isalpha()
*   checks  for an alphabetic character; in the standard "C" locale,
*   it is equivalent to (isupper(c) ||  islower(c)).   In  some  lo‐
*   cales, there may be additional characters for which isalpha() is
*   true—letters which are neither uppercase nor lowercase.
**/

int	ft_isalpha(int c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}
