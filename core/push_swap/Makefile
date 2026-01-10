# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME        = push_swap
BONUS_NAME  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

INCLUDES    = -Iincludes -Ilibft
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

SRC_DIR     = src
OBJ_DIR     = obj

SRC_FILES   = \
	main.c \
	parse.c \
	stack_init.c \
	utils/error.c \
	utils/free.c \
	utils/is_sorted.c \
	operations/swap.c \
	operations/push.c \
	operations/rotate.c \
	operations/reverse_rotate.c \
	algos/sort_2.c \
	algos/sort_3.c \
	algos/sort_5.c \
	algos/radix.c

SRCS        = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# **************************************************************************** #
#                                    BONUS                                     #
# **************************************************************************** #

BONUS_DIR   = bonus
BONUS_SRC   = checker_bonus.c
BONUS_SRCS  = $(addprefix $(BONUS_DIR)/, $(BONUS_SRC))
BONUS_OBJS  = $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:.c=.o))

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(OBJS) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

# **************************************************************************** #
#                               OBJECT RULES                                   #
# **************************************************************************** #

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# **************************************************************************** #
#                                   CLEAN                                      #
# **************************************************************************** #

clean:
	@make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
