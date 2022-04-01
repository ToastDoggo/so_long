# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rehernan <rehernan@students.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 19:09:03 by rehernan          #+#    #+#              #
#    Updated: 2022/04/01 23:12:19 by rehernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = ./SRC/so_long.c ./SRC/utils.c ./SRC/map_checks.c ./SRC/map_drawer.c

HEADER_FILES = ./SRC/so_long.h ./ft_printf/ft_printf.h ./libft/libft.h \
				./MLX42/MLX42.h
CFLAGS = -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

$(NAME): $(SRC) ft_printf/libftprintf.a MLX/libmlx42.a
#	gcc $(SRC) -g libftprintf.a libmlx42.a -lglfw3 -L ./MLX/GLFW/lib-universal -framework OpenGL -framework IOKit -framework Cocoa -o $(NAME)
	gcc $(SRC) -g libftprintf.a libmlx42.a -lglfw -ldl -o $(NAME)
	@echo "So long and thanks for the fish!"
%.o: %.c $(HEADER_FILES)
	@echo "Fishing..."
	$(CC) -c $(CFLAGS) -o $@ $<

ft_printf/libftprintf.a:
	make -C ft_printf
	cp ft_printf/libftprintf.a .
	@echo "Making libftprintf..."

MLX/libmlx42.a:
	make -C MLX
	cp MLX/libmlx42.a .
	@echo "Making MLX42..."

clean:
	@echo "Executable files are gone."

fclean: clean
	rm -f $(NAME)
	make -C ft_printf fclean
	make -C MLX fclean
	rm -f libftprintf.a
	rm -f libmlx42.a
	rm -rf $(NAME).dSYM
	@echo "This is squeaky clean!"

re: fclean all
	@echo "Fishing again was succesful!"

.PHONY: all clean fclean re