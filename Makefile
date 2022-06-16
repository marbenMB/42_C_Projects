# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 22:56:04 by mbenbajj          #+#    #+#              #
#    Updated: 2022/01/11 22:56:08 by mbenbajj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ./src/ft_printf_utils.c ./src/ft_deal_with.c \
		./src/ft_process_char_cases.c ./src/ft_process_nbr_cases.c ./libft/ft_put.c

OBJECT = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJECT) ft_printf.h
	ar rc $(NAME) $(OBJECT)

%.o : %.c ft_printf.h
	cc $(CFLAGS) -c $< -o $@

bonus : all

clean :
	rm -rf $(OBJECT)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean all re