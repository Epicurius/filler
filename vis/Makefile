# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/29 14:32:02 by nneronin          #+#    #+#              #
#    Updated: 2021/05/29 14:32:05 by nneronin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED				:= "\e[0;31m"
GREEN			:= "\e[0;32m"
YELLOW			:= "\e[0;33m"
BLUE			:= "\e[0;34m"
MAGENTA			:= "\e[0;35m"
CYAN			:= "\e[0;36m"
RESET			:= "\e[0m"

NAME = vis

SRCS =	./read_input.c\
		./draw.c\
		./help_func.c\
		./key.c\
		./brains.c\
		./main.c

FLAGS = -Wall -Werror -Werror
OBJ = $(SRCS:.c=.o)

LIB_DIR	:= ../lib
LIBFT	:= -I $(LIB_DIR)/libft $(LIB_DIR)/libft/libft.a
LIBPF	:= -I $(LIB_DIR)/libpf $(LIB_DIR)/libpf/libpf.a
FLAGS	:= -Wall -Wextra -Werror

all: libs $(NAME)
	@printf $(GREEN)"vis ready!\n"$(RESET)

$(NAME):
	@gcc -o $(NAME) -g $(SRCS) $(LIBFT) $(LIBPF) -L./mlx/ -lmlx -framework OpenGL -framework AppKit
	@printf $(CYAN)"[INFO]	vis was successfully created.\n"$(RESET)

libs: $(LIB_DIR)
	@make -C ../lib/libft
	@make -C ../lib/libpf
	@printf $(CYAN)"[INFO]	All libs compiled.\n"$(RESET)

clean:
	@/bin/rm -f $(OBJS)
	@echo "$(NAME) was cleaned."

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean, all, re, fclean
