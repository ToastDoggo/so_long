/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:37:52 by rehernan          #+#    #+#             */
/*   Updated: 2021/08/16 13:48:38 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*potat;

	while (*lst)
	{
		potat = *lst;
		del(potat -> content);
		*lst = (*lst)->next;
		free(potat);
	}
	*lst = NULL;
}
