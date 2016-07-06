# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aulamber <aulamber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/30 18:22:12 by aulamber          #+#    #+#              #
#    Updated: 2014/05/04 20:47:55 by aulamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=			ft_select

SRC		=	./

INCDIR 	=	includes/

SOURCE 	=	main.c \
			list_functions.c \
			other_functions.c \
			other_functions_3.c \

OBJ 	=		$(SOURCE:.c=.o)

LIB 	=		libft/libft.a

LINE = -Llibft -lft -L/usr/lib/ -ltermcap

CC 		=		gcc

FLAG =		-I $(INCDIR) -Wall -Wextra -Werror -g

RED = \033[33;31m
BLUE = \033[33;34m
GREEN = \033[33;32m
RESET = \033[0m

.PHONY: all re fclean

all: $(NAME)

$(LIB):
		@$(MAKE) -C libft/

$(NAME): $(LIB) $(OBJ)
		@$(CC) -o $(NAME) $(FLAG) $^ $(LINE)
		@echo "[$(GREEN)Compilation $(BLUE)$(NAME) $(GREEN)ok$(RESET)]"

%.o: %.c
		@$(CC) -c -o $@ $(FLAG) $^

clean:
	@cd libft/ && $(MAKE) $@
	@rm -f $(OBJ)
	@echo "[$(RED)Supression des .o de $(BLUE)$(NAME) $(GREEN)ok$(RESET)]"

fclean: clean
		@cd libft/ && $(MAKE) $@
		@rm -f $(NAME)
		@echo "[$(RED)Supression de $(BLUE)$(NAME) $(GREEN)ok$(RESET)]"

re: fclean all
