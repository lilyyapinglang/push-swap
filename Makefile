# Name
NAME = push_swap

# Directory Paths
SRC_DIR = src
OBJ_DIR = build
INC_DIR = includes

# Compile
CC  = cc
CFLAGS := -Wall -Wextra -Werror -I$(INC_DIR)

# Sources files
SRCS = \
  main.c \
  split_strs.c parse_n_check.c arr_str_utils.c \
  calculate_cost.c update_position.c \
  error_free_mem.c \
  init_stack.c \
  num_utils.c \
  ops_reverse_rotate.c ops_rotate.c ops_swap_n_push.c\
  reinsert_b_to_a.c rotate_a_to_correct_order.c rotate_both_stacks_to_prepare.c\
  sort_nums_less_5.c sort_stack.c 
 
# Derived paths 
SRC_PATHS := $(addprefix $(SRC_DIR)/,$(SRCS))
OBJ_PATHS := $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_PATHS)
	$(CC) $(CFLAGS) $(OBJ_PATHS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(INC_DIR) $(SRC_DIR)

.PHONY: all clean fclean re norm
