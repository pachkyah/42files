NAME        = philo

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -pthread
# Add -fsanitize=thread during debugging to catch data races!
#CFLAGS    += -fsanitize=thread -g3 

INCLUDES    = -Iinclude -Ilibft

SRC_DIR     = src
OBJ_DIR     = obj
LIBFT_DIR   = libft

SRCS        = \
    $(SRC_DIR)/main.c \
    $(SRC_DIR)/init.c \
    $(SRC_DIR)/simulation.c \
    $(SRC_DIR)/utils.c \
	$(SRC_DIR)/actions.c \
	$(SRC_DIR)/monitoring.c \
#    $(SRC_DIR)/cleanup.c

OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT       = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

# Compile libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Link the final executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re