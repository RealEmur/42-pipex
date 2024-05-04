NAME = pipex
FILES = pipex.c 
OBJS = $(FILES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = lib/libft/
LIBFT_NAME = libft.a

PRINTF_DIR = lib/libftprintf/
PRINTF_NAME = libftprintf.a


all: $(NAME)

$(NAME): libft printf $(OBJS)
	gcc $(OBJS) $(PRINTF_DIR)$(PRINTF_NAME) $(LIBFT_DIR)$(LIBFT_NAME) -o $(NAME)

libft:
	make -C $(LIBFT_DIR)

printf: 
	make -C $(PRINTF_DIR)

clean:
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean 
	make fclean	-C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all 