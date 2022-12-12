NAME = libftprintf.a

CC = clang

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c\
		toolbox.c\

SRC_OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC_OBJ)
	ar -r $(NAME) $(SRC_OBJ)

clean: 
	rm -f $(SRC_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re