# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/28 16:39:45 by emheuga           #+#    #+#              #
#    Updated: 2026/03/28 16:39:48 by emheuga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        = push_swap
BONUS       = checker
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
INCLUDE     = include
SRC_DIR     = sources
BONUS_DIR   = bonus
UTILS_DIR   = utils

SRCS = \
$(SRC_DIR)/main.c \
$(SRC_DIR)/operations/push.c \
$(SRC_DIR)/operations/reverse_rotate.c \
$(SRC_DIR)/operations/rotate.c \
$(SRC_DIR)/operations/swap.c \
$(SRC_DIR)/parsing/check.c \
$(SRC_DIR)/parsing/indexer.c \
$(SRC_DIR)/parsing/is_sorted.c \
$(SRC_DIR)/sorting/big_sorter.c \
$(SRC_DIR)/sorting/little_sorter.c \
$(SRC_DIR)/stack/add_to_stack.c \
$(SRC_DIR)/stack/free_stack.c \
$(SRC_DIR)/stack/new_node.c \
$(UTILS_DIR)/ft_atoi.c \
$(UTILS_DIR)/ft_split.c \
$(UTILS_DIR)/ft_strcmp.c

BONUS_SRCS = \
$(BONUS_DIR)/checker.c \
$(BONUS_DIR)/do_op.c \
$(SRC_DIR)/operations/push.c \
$(SRC_DIR)/operations/reverse_rotate.c \
$(SRC_DIR)/operations/rotate.c \
$(SRC_DIR)/operations/swap.c \
$(SRC_DIR)/parsing/check.c \
$(SRC_DIR)/parsing/indexer.c \
$(SRC_DIR)/parsing/is_sorted.c \
$(SRC_DIR)/stack/add_to_stack.c \
$(SRC_DIR)/stack/free_stack.c \
$(SRC_DIR)/stack/new_node.c \
$(UTILS_DIR)/ft_atoi.c \
$(UTILS_DIR)/ft_split.c \
$(UTILS_DIR)/ft_strcmp.c

OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I$(INCLUDE) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -I$(INCLUDE) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
