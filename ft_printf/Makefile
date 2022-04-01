# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rehernan <rehernan@students.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 17:40:51 by rehernan          #+#    #+#              #
#    Updated: 2022/03/04 12:24:57 by rehernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
OUTPUT = ft_printf.o numbers.o utils.o
HEADER_FILES = ft_printf.h ./libft/libft.h
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(OUTPUT) libft/libft.a
	ar rc $@ $^
%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

libft/libft.a:
	make -C libft
	cp ./libft/libft.a $(NAME)

clean:
	rm -f $(OUTPUT)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re