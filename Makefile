NAME = nneronin.filler
SRCS =	./srcs/read_input.c\
		./srcs/help_func.c\
		./srcs/brains.c\
		./srcs/main.c
OBJS =	./srcs/read_input.o\
		./srcs/help_func.o\
		./srcs/brains.o\
		./srcs/main.o
INCLUDES = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc -o $(NAME) $(SRCS) $(INCLUDES)
	@echo "$(NAME) was successfully created."

clean:
	@/bin/rm -f $(OBJS)
	@echo "$(NAME) was cleaned."

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean, all, re, fclean
