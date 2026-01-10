NAME        = pipex

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -Iinclude -Ilibft

SRC_DIR     = src
OBJ_DIR     = obj
LIBFT_DIR   = libft

SRCS        = \
	$(SRC_DIR)/cleanup.c \
	$(SRC_DIR)/exec.c \
	$(SRC_DIR)/files.c \
	$(SRC_DIR)/heredoc_bonus.c \
	$(SRC_DIR)/init.c \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/parsing.c \
	$(SRC_DIR)/path.c \
	$(SRC_DIR)/pipes.c \
	$(SRC_DIR)/utils.c

OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT       = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Object rule (VERY IMPORTANT)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

# Phony
.PHONY: all clean fclean re