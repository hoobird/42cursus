CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c 

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

BUFFER_SIZE = 42
BUFFER_FLAG = -D BUFFER_SIZE=

LIBFTPATH = ./libft
LIBFT = ./libft/libft.a


all:	$(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ) 
	
$(OBJ):	$(SRC)
	$(CC)  $(CFLAGS) -c $(SRC) $(BUFFER_FLAG) $(BUFFER_SIZE)

$(LIBFT):
	make -C $(LIBFTPATH) all
	
clean:
	make -C $(LIBFTPATH) clean
	rm -f $(OBJ) $(OBJB)
	
fclean:	clean
	make -C $(LIBFTPATH) fclean
	rm -f $(NAME)

re:	fclean all
	
.PHONY: all fclean clean re libft
