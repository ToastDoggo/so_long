/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 14:06:36 by rehernan          #+#    #+#             */
/*   Updated: 2021/08/16 14:34:41 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*potat2;
	t_list	*ketchup;

	if (!lst)
		return (NULL);
	potat2 = NULL;
	ketchup = NULL;
	while (lst)
	{
		ketchup = ft_lstnew(f(lst -> content));
		if (!ketchup)
		{
			ft_lstclear(&potat2, del);
			return (NULL);
		}
		ft_lstadd_back(&potat2, ketchup);
		lst = lst -> next;
	}
	return (potat2);
}
