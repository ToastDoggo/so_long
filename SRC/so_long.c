/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:23:01 by rehernan          #+#    #+#             */
/*   Updated: 2022/04/01 23:24:49 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hook(void *images)
{
	mlx_t	*mlx;
	t_graphics	*image;

	image = (t_graphics *) images;
	mlx = image->mlx;
	// ft_draw(images);
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP) || \
		mlx_is_key_down(mlx, MLX_KEY_DOWN) || \
		mlx_is_key_down(mlx, MLX_KEY_LEFT) || \
		mlx_is_key_down(mlx, MLX_KEY_RIGHT))
			return ;//ft_move_protagonist(param, key);
}

int32_t	main(int argc, char *argv[])
{
	t_graphics	images;
	// mlx_image_t *temp;

	if (argc != 2)
		return (0);
	images.map = ft_map_checker(argv);
	// t_list *copy = images.map;
	// while (copy)
	// {
	// 	ft_printf("%s\n", copy->content);
	// 	copy = copy->next;
	// }
	images.mlx = mlx_init(1280, 720, "so_long", true);
	// temp = mlx_new_image(images.mlx, 1280, 720);
	// images.image = &temp;
	mlx_loop_hook(images.mlx, &hook, &images);
	if (!images.mlx)
	{
		ft_putstr_fd("HELP", 1);
		exit(1);
	}
	ft_draw(&images);
	//mlx_loop_hook(images.mlx, ft_draw, (void *) &images);
	mlx_loop(images.mlx);
	return (0);
}
