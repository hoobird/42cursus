CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = server.c client.c
NAME = server client
FTPRINTF_PATH = ./ft_printf
FTPRINTF = $(FTPRINTF_PATH)/libftprintf.a
LIBFT_PATH = $(FTPRINTF_PATH)/libft
LIBFT = $(FTPRINTF_PATH)/libft/libft.a

all: $(NAME)

$(NAME): $(SRCS) $(FTPRINTF) $(LIBFT)
	$(CC) $(CFLAGS) server.c $(FTPRINTF) $(LIBFT) -o server
	$(CC) $(CFLAGS) client.c $(FTPRINTF) $(LIBFT) -o client

$(FTPRINTF):
	make -C $(FTPRINTF_PATH) all

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	rm -f $(OBJ)
	make -C $(FTPRINTF_PATH) clean
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(FTPRINTF_PATH) fclean
	make -C $(LIBFT_PATH) fclean

re:	fclean all

phony: all fclean clean re libft ft_printf
