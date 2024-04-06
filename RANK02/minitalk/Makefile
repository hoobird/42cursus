CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = client.c server.c
OBJS = $(SRCS:.c=.o)
TSERVER = server.o
TCLIENT = client.o
FTPRINTF_PATH = ./ft_printf
FTPRINTF = $(FTPRINTF_PATH)/libftprintf.a

all: $(NAME)

lol : $(FTPRINTF)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ):	$(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

$(FTPRINTF):
	make -C $(FTPRINTF_PATH) all

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

fclean: clean
	rm -f $(TARGET)

re:	fclean all

phony: all fclean clean re libft ft_printf