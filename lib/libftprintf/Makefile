NAME = libftprintf.a
SRCS = ./ft_printf.c ./utils/ft_putchar.c ./handlers/handle_char.c ./handlers/handle_string.c ./utils/ft_putstr.c \
		./utils/print_base.c ./handlers/handle_hex_lower.c ./handlers/handle_hex_upper.c ./handlers/handle_address.c ./handlers/handle_int.c \
		./handlers/handle_unsigned_int.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all
