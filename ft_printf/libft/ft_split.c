/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 19:10:31 by rehernan          #+#    #+#             */
/*   Updated: 2021/08/15 12:05:52 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countchr(char const *s, char c)
{
	size_t	i;
	size_t	ctr;
	size_t	boo;

	i = 0;
	ctr = 0;
	boo = 0;
	while (s[ctr])
	{
		if (s[ctr] != c && boo == 0)
		{
			boo = 1;
			i++;
		}
		else
			boo = 0;
		ctr++;
	}
	return (i);
}

static char	*smth(const char *s, int start, int end)
{
	char	*aaa;
	int		i;

	i = 0;
	aaa = malloc(end - start + 1);
	if (!aaa)
		return (NULL);
	while (end > start)
		aaa[i++] = s[start++];
	aaa[i] = '\0';
	return (aaa);
}

char	**ft_split(char const *s, char c)
{
	int		start;
	size_t	i;
	size_t	j;
	char	**dest;

	if (!s)
		return (NULL);
	dest = ft_calloc((countchr(s, c) + 1), sizeof(char *));
	if (!dest)
		return (NULL);
	start = -1;
	i = 0;
	j = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start == -1)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			dest[j++] = smth(s, start, i);
			start = -1;
		}
		i++;
	}
	return (dest);
}
