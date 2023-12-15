CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

NAME = get_next_line.a

BUFFER_SIZE = 10
BUFFER_FLAG = -D BUFFER_SIZE=$(BUFFER_SIZE)


all:	$(NAME)

$(NAME): $(OBJ) 
	ar rcs $(NAME) $(OBJ) 
	
$(OBJ):	$(SRC)
	$(CC)  $(CFLAGS) -c $(SRC) # $(BUFFER_FLAG) 
	
clean:
	rm -f $(OBJ) $(OBJB)
	
fclean:	clean
	rm -f $(NAME)

re:	fclean all
	
.PHONY: all fclean clean re libft
