files = main.c functions/ft_split.c functions/ft_strlen.c functions/ft_strjoin.c functions/ft_strncmp.c 
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all:
	$(CC) $(CFLAGS) $(files) 