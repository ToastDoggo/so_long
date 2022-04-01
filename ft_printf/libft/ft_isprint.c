/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 22:18:59 by rehernan          #+#    #+#             */
/*   Updated: 2021/07/09 22:24:35 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** isprint()
*   checks for any printable character including space.
**/

int	ft_isprint(int c)
{
	return (c >= ' ' && '~' >= c);
}
