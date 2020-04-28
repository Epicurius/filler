NAME = nik.filler
SRCS = ./read_input.c\
	./help_func.c\
	./brains.c
OBJS = ./read_input.o\
	./help_func.o\
	./brains.o
INCLUDES = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRCS) $(INCLUDES)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean, all, re, fclean
