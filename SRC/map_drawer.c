/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:59:29 by rehernan          #+#    #+#             */
/*   Updated: 2022/04/01 23:21:15 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw(t_graphics	*images)
{
	xpm_t		*draw;
	t_list 		*cpy;
	char 		*str;
	int			i;
	int			y;

	y = 0;
	i = 0;
	draw = mlx_load_xpm42("../assets/so_long_wall.xpm42");
	mlx_image_t *W = mlx_texture_to_image(images->mlx, &(draw->texture));
	mlx_delete_xpm42(draw);
	draw = mlx_load_xpm42("../assets/so_long_closed_door.xpm42");
	mlx_image_t *E = mlx_texture_to_image(images->mlx, &(draw->texture));
	mlx_delete_xpm42(draw);
	draw = mlx_load_xpm42("../assets/so_long_floor.xpm42");
	mlx_image_t *F = mlx_texture_to_image(images->mlx, &(draw->texture));
	mlx_delete_xpm42(draw);
	draw = mlx_load_xpm42("../assets/so_long_sneaky_toast.xpm42");
	mlx_image_t *C = mlx_texture_to_image(images->mlx, &(draw->texture));
	mlx_delete_xpm42(draw);	cpy = images->map;
	draw = mlx_load_xpm42("../assets/so_long_dog_front.xpm42");
	mlx_image_t *P = mlx_texture_to_image(images->mlx, &(draw->texture));
	mlx_delete_xpm42(draw);	cpy = images->map;
	while (cpy)
	{
		str = cpy->content;
		i = 0;
		while(str && str[i] != '\0')
		{
			// if (str[i] == '1')
			// 	draw = mlx_load_xpm42("../assets/so_long_wall.xpm42");
			// else if (str[i] == 'E')
			// 	draw = mlx_load_xpm42("../assets/so_long_closed_door.xpm42");
			// else if (str[i] == '0')
			// 	draw = mlx_load_xpm42("../assets/so_long_floor.xpm42");
			// else if (str[i] == 'C')
			// 	draw = mlx_load_xpm42("../assets/so_long_sneaky_toast.xpm42");
			// else if (str[i] == 'P')
			// 	draw = mlx_load_xpm42("../assets/so_long_dog_front.xpm42");
			if (str[i] == '1')
				mlx_image_to_window(images->mlx, W, i * 32, y * 32, 0);
			else if (str[i] == 'E')
				mlx_image_to_window(images->mlx, E, i * 32, y * 32, 0);
			else if (str[i] == '0')
				mlx_image_to_window(images->mlx, F, i * 32, y * 32, 0);
			else if (str[i] == 'C')
				mlx_image_to_window(images->mlx, C, i * 32, y * 32, 0);
			else if (str[i] == 'P')
				mlx_image_to_window(images->mlx, P, i * 32, y * 32, 0);
			// if (i == 0 && y == 0)
			//*(images->image) = mlx_texture_to_image(images->mlx, &(draw->texture));
			// else
			// if (mlx_draw_texture(*(images->image), &(draw->texture), i * 32, y * 32) == false)
			// 	ft_putstr_fd("images error\n", 2);
			//mlx_delete_image(images->mlx, t);
			i++;
		}
		y++;
		cpy = cpy->next;
	}
	// mlx_image_to_window(images->mlx, *(images->image), 0, 0, 0);
}

t_list	*ft_map_done(char *argv)
{
	t_list	*map;
	int		file;
	char	*str;

	file = open(argv, O_RDONLY);
	str = get_next_line(file);
	map = ft_lstnew(str);
	while (str)
	{
		str = get_next_line(file);
		ft_lstadd_back(&map, ft_lstnew(str));
	}
	return (map);
}
