# Makefile for library
NAME	= libftprintf.a
# Compiler and flags
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -fr

# Paths
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = ft_printf.c flag_parsing.c print_handlers.c utils.c
OBJS = $(SRCS:.c=.o)

# Default rule: build libftprintf.a

all: $(LIBFT) $(NAME)

# Build ft_printf .o files
%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -c $< -o $@

# Build libft.a if it doesn't exist
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

# Create the static library from .o files and merge libft.a objects into it
$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

# Bonus is the same as mandatory part
bonus: $(LIBFT) $(NAME)

# Clean object files
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

# Clean all, including library
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re

