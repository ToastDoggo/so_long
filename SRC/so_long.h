/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:23:51 by rehernan          #+#    #+#             */
/*   Updated: 2022/04/01 23:25:02 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../MLX/include/MLX42/MLX42.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_graphics
{
	mlx_t	*mlx;
	mlx_image_t	**image;
	t_list	*map;
	int		score;
	int		movement;
}	t_graphics;

//void ft_move_protagonist(mlx_t *param, enum *keys);
int		ft_searchchr(char *s, char c);
void	ft_draw(t_graphics	*images);
t_list	*ft_map_checker(char *argv[]);
int32_t		main(int argc, char **argv);
t_list	*ft_map_done(char *argv);

#endif