# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/29 11:14:02 by nneronin          #+#    #+#              #
#    Updated: 2021/05/30 16:36:15 by nneronin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED				:= "\e[0;31m"
GREEN			:= "\e[0;32m"
YELLOW			:= "\e[0;33m"
BLUE			:= "\e[0;34m"
MAGENTA			:= "\e[0;35m"
CYAN			:= "\e[0;36m"
RESET			:= "\e[0m"

NAME = nneronin.filler

SRCS =	./srcs/read_input.c\
		./srcs/help_func.c\
		./srcs/brains.c\
		./srcs/main.c

OBJS =	./srcs/read_input.o\
		./srcs/help_func.o\
		./srcs/brains.o\
		./srcs/main.o

LIB_DIR	:= ./lib
LIBFT	:= -I $(LIB_DIR)/libft $(LIB_DIR)/libft/libft.a
LIBPF	:= -I $(LIB_DIR)/libpf $(LIB_DIR)/libpf/libpf.a
FLAGS	:= -Wall -Wextra -Werror

all: libs $(NAME)
	@printf $(GREEN)"nneronin.filler ready!\n"$(RESET)

$(NAME):
	@gcc -o $(NAME) $(SRCS) $(LIBFT) $(LIBPF) $(FLAGS)
	@printf $(CYAN)"[INFO]	nneronin.filler was successfully created.\n"$(RESET)

libs: $(LIB_DIR)
	@make -C ./lib/libft
	@make -C ./lib/libpf
	@printf $(CYAN)"[INFO]	All libs compiled.\n"$(RESET)

clean:
	@/bin/rm -f $(OBJS)
	@echo "$(NAME) was cleaned."

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean, all, re, fclean
