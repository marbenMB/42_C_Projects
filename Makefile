NAME = push_swap
SRC = push_swap.c push_swap_utils.c ft_check.c error_handling.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) push_swap.h
	make bonus -C ./libft
	gcc $(SRC) -o $(NAME) ./libft/libft.a -g

clean :
	make clean -C ./libft 
	rm -rf $(OBJ)

fclean :
	make fclean -C ./libft
	rm -rf $(OBJ) $(NAME) push_swap.dSYM

re : fclean all

.PHONY : clean fclean all re bonus