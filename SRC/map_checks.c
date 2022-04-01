/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:15:24 by rehernan          #+#    #+#             */
/*   Updated: 2022/03/30 17:20:39 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	special_counter(int file, int *e, int *c, int *p)
{
	char	*str;
	int		wall;

	wall = 0;
	*e = 0;
	*c = 0;
	*p = 0;
	str = get_next_line(file);
	while (str)
	{
		*e += ft_searchchr(str, 'E');
		*c += ft_searchchr(str, 'C');
		*p += ft_searchchr(str, 'P');
		str = get_next_line(file);
		wall++;
	}
	return (wall);
}

int	wall_checker(char *argv, int wall)
{
	int		file;
	int		x;
	int		y;
	char	*str;

	x = wall;
	file = open(argv, O_RDONLY);
	str = get_next_line(file);
	if (ft_searchchr(str, '1') != ft_strlen(str) - 1)
		return (1);
	y = ft_searchchr(str, '1');
	str = get_next_line(file);
	x--;
	while (x > 1)
	{
		if (y == ft_strlen(str) - 1 && str[0] == '1' && str[y - 1] == '1')
			x--;
		else
			return (1);
		str = get_next_line(file);
	}
	if (ft_searchchr(str, '1') != y)
		return (1);
	return (0);
}

int	check_end(char *str)
{
	char	*extension;

	extension = ft_strrchr(str, '.');
	return (ft_strncmp(extension, ".ber\0", 5));
}

t_list	*ft_map_checker(char *argv[])
{
	int		go_out;
	int		collect;
	int		protagonist;
	int		wall;
	int		file;

	file = open(argv[1], O_RDONLY);
	if (file <= 0 || check_end(argv[1]))
	{
		ft_putstr_fd("Invalid extension\nYEET\n", 1);
		exit(1);
	}
	wall = special_counter(file, &go_out, &collect, &protagonist);
	close(file);
	if (go_out < 1 || collect < 1 || protagonist < 1)
		ft_putstr_fd("This map isn't valid.\nYEET\n", 1);
	else if (protagonist > 1)
		ft_putstr_fd("You can't have more than one dog!\nYEET\n", 1);
	else if (wall_checker(argv[1], wall) == 1)
		ft_putstr_fd("The walls aren't rectangular!\nYEET\n", 1);
	else
		return(ft_map_done(argv[1]));
	exit(1);
}
