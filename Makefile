# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychahbar <ychahbar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 11:58:17 by ychahbar          #+#    #+#              #
#    Updated: 2019/06/06 23:48:23 by asouat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS =	main.c \
		check_input.c \
		lst_tools.c \
		ft_coordonate.c \
		ft_perspective.c \
		ft_bresenham.c \
		ft_bresenham_tool.c \
		ft_bresenham_2.c \
		ft_bresenham_2_tool.c \
		ft_tools.c \
		ft_render.c \
		ft_free_memory.c

OBJECTS = $(SRCS:.c=.o)

HEADERS = fdf.h minilibx_macos/mlx.h

LIBRARIES = -L minilibx_macos -lmlx -L libft -lft

FRAMEWORKS = -framework OpenGl -framework Appkit

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME):$(OBJ)
	@make -C libft/
	@make -C minilibx_macos/
	@gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS) $(LIBRARIES) $(FRAMEWORKS)

clean:
	@make clean -C libft/
	@make clean -C minilibx_macos/
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all

.PHONY : fclean clean all re
