# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 13:58:33 by abellakr          #+#    #+#              #
#    Updated: 2022/07/06 13:09:27 by mbenbajj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	**********************			**********************
#                            ****                        *
#	**********************			**********************

Color_Off='\033[0m'       # Text Reset

# Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

# Bold
BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White

#	**********************			**********************
#                            RULES                       *
#	**********************			**********************

NAME = minishell

CC = cc

CFlAGS = -Wall -Wextra -Werror

HEADS = headers/includes.h headers/macros.h headers/structs.h execution/headers/execution.h

READ_FLAGS    =  -I $(shell brew --prefix readline)/include \
				-L$(shell brew --prefix readline)/lib -lreadline -lhistory

EXEC_SRC = execution/utils/proccess_buffer.c execution/utils/ft_check.c execution/utils/ft_utils.c \
			execution/utils/ft_errors.c execution/utils/analyse_exec.c execution/utils/execute_cmd.c \
			execution/utils/execution_func.c execution/utils/signals.c\
			execution/builtins/ft_echo/ft_echo.c execution/builtins/ft_env/ft_env.c execution/builtins/ft_exit/ft_exit.c \
			execution/builtins/ft_export/ft_export.c execution/builtins/ft_export/sort_env_utils.c \
			execution/builtins/ft_export/add_env_var.c execution/builtins/ft_export/add_var_utils.c execution/builtins/ft_export/sorted_env.c\
			execution/builtins/ft_pwd/ft_pwd.c execution/builtins/ft_unset/ft_unset.c  \
			execution/builtins/ft_cd/ft_cd.c execution/builtins/ft_cd/cd_utils.c

LEX_SRC = minishell.c ./lexer/lexer_first_part.c ./lexer/lexer_utils.c ./lexer/tools.c ./lexer/syntax_error.c ./lexer/lexer_second_part.c \
		./expander/expander.c ./expander/expander_utils1.c ./expander/get_env.c ./expander/expande_variable.c ./expander/expander_utils2.c \
		./expander/expander_utils3.c ./lexer/lexer_third_part.c ./lexer/lexer_part_four.c ./heredoc/heredoc_first.c ./heredoc/heredoc_sec.c

SRC = $(LEX_SRC) $(EXEC_SRC)	

OBJ = $(SRC:.c=.o)

%.o: %.c $(SRC) $(HEADS)
	@$(CC) -I $(shell brew --prefix readline)/include $(CFlAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@echo  $(BPurple)"------------------------------------------------"$(Color_Off)
	@echo
	@echo  $(BPurple)"	minishell by group sbaksi : done! "$(Color_Off)
	@echo
	@echo  $(BPurple)"------------------------------------------------"$(Color_Off)
	@make -C ./libft
	@$(CC) $(CFlAGS) $(READ_FLAGS) $(OBJ) ./libft/libft.a -o $(NAME)
	@make clean

clean : 
	@make clean -C ./libft
	@rm -f $(OBJ)

fclean : clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re : fclean all

.PHONY : clean fclean bonus re
