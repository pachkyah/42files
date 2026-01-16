NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
MINILIBX = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm
INCLUDES = -Iinclude -Ilibft -I$(MINILIBX_DIR)

SRC_DIR     = src
OBJ_DIR     = obj
LIBFT_DIR   = libft
MINILIBX_DIR= minilibx-linux

SRCS = \
	$(SRC_DIR)/error.c \
	$(SRC_DIR)/floodfill.c \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/map_check.c \
	$(SRC_DIR)/map_read.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/walls_check.c \
	$(SRC_DIR)/elements_check.c \
	$(SRC_DIR)/player.c \
	$(SRC_DIR)/render.c \
	$(SRC_DIR)/input.c 

OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT       = $(LIBFT_DIR)/libft.a
MLX          = $(MINILIBX_DIR)/libmlx.a

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MINILIBX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

# Phony
.PHONY: all clean fclean re
