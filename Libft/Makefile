CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr \
ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd \
ft_putstr_fd ft_putendl_fd ft_putnbr_fd

OBJ = $(SRC:.c=.o)

NAME = libft.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)
	
$(OBJ):	$(SRC)
	$(CC)  $(CFLAGS) -c $(SRC)

clean:
	rm -f $(OBJ)
	
fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)
	
.PHONY: all fclean clean re 
