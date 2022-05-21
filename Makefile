# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 17:21:59 by mbenbajj          #+#    #+#              #
#    Updated: 2022/05/12 17:22:02 by mbenbajj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = manda/so_long.c manda/error_handling.c manda/ft_check.c manda/draw_map.c \
		manda/ft_draw_utils.c manda/ft_play_utils.c manda/moves.c \
		manda/ft_parsing_utils.c manda/ft_utils_parsing.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJ = $(SRC:.c=.o)

SRC_BNS = bonus/so_long.c bonus/error_handling.c bonus/ft_check.c bonus/draw_map.c \
		bonus/ft_draw_utils.c bonus/ft_play_utils.c bonus/moves.c \
		bonus/ft_parsing_utils.c bonus/ft_utils_parsing.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJ_BNS = $(SRC_BNS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
FRAM = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJ) manda/so_long.h
	make bonus -C ./libft
	gcc $(SRC) $(FRAM) -o $(NAME) ./libft/libft.a

bonus : $(OBJ_BNS) bonus/so_long.h
	make bonus -C ./libft
	gcc $(SRC_BNS) $(FRAM) -o $(NAME) ./libft/libft.a

clean :
	make clean -C ./libft
	rm -rf $(OBJ) $(OBJ_BNS)

fclean :
	make fclean -C ./libft
	rm -rf $(OBJ) $(OBJ_BNS) $(NAME) so_long.dSYM .vscode

re : fclean all

.PHONY : all clean fclean re bonus