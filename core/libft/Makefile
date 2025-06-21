# Makefile for libft
NAME	= libft.a
# Compiler and flags
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

SRC		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		  ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		  ft_atoi.c ft_calloc.c ft_strdup.c

OBJ		= $(SRC:.c=.o)

# Default target
all: $(NAME)

# Create libft.a from object files
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Remove object files
clean:
	$(RM) $(OBJ)

# Remove object files and the library
fclean: clean
	$(RM) $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
