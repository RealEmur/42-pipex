NAME = pipex
FILES = pipex.c ./functions/ft_split.c ./functions/ft_strlen.c functions/ft_strjoin.c functions/ft_strncmp.c ./functions/ft_putstr.c ./utils/send_error.c ./utils/swap_str_and_free.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(FILES) -o $(NAME)

clean:
	echo "Maksat boş kalmasın"

fclean: clean 
	$(RM) $(NAME)

re: fclean all 