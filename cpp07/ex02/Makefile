# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 13:50:09 by gcavanna          #+#    #+#              #
#    Updated: 2024/01/30 12:59:20 by gcavanna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AA

SRC = main.cpp
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

# Colors:
GREEN = \e[92m
RED = \e[91m
GRAY = \e[90m
RESET = \e[0m

all: $(NAME)

$(NAME):
	@printf "$(GRAY)    - Compiling, stupid who reads $(NAME)... $(RESET)\n"
	@ $(CC) $(FLAGS) $(SRC) -o $(NAME)
	@printf "$(GREEN)    - yoyo the executable is here.$(RESET)\n"

clean:
	@$(RM) $(NAME)
	@printf "$(RED)    - i'm done.$(RESET)\n"

fclean: clean

re: fclean all

.PHONY: all clean fclean re