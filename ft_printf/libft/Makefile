# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rehernan <rehernan@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/10 11:52:30 by rehernan          #+#    #+#              #
#    Updated: 2022/03/24 20:34:58 by rehernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
OBJ_FILES = ft_memset.o ft_memcmp.o ft_bzero.o ft_isascii.o \
			ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_isalpha.o \
			ft_isdigit.o ft_isalnum.o ft_isprint.o ft_calloc.o \
			ft_toupper.o ft_tolower.o ft_strrchr.o ft_memchr.o \
			ft_memcpy.o ft_memmove.o ft_strlcpy.o ft_strlcat.o ft_strncmp.o \
			ft_putnbr_fd.o ft_strnstr.o ft_atoi.o ft_substr.o \
			ft_strmapi.o ft_striteri.o ft_strtrim.o ft_itoa.o ft_split.o \
			get_next_line_bonus.o get_next_line_utils_bonus.o

BONUS = 	ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o \
			ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o \
			ft_lstmap.o
			
HEADER_FILES = libft.h get_next_line_bonus.h
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_FILES) $(BONUS)
	ar rc $@ $^
bonus: $(BONUS)
	ar rc $(NAME) $^
%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_FILES) $(BONUS)

fclean: clean
	rm -f $(NAME) libft.so *.out

re: fclean all

.PHONY: all clean fclean re
