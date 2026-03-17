NAME    = push_swap
BONUS   = checker
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g
SRC     = sources
BONUS_SRC = bonus
INCLUDE = include

SRCS    = $(SRC)/operations.c \
          $(SRC)/chek.c \
          $(SRC)/ft_atoi.c \
          $(SRC)/ft_split.c \
          $(SRC)/indexer.c \
          $(SRC)/is_sorted.c \
          $(SRC)/little_sorter.c \
          $(SRC)/big_sorter.c \
          $(SRC)/main.c

BONUS_SRCS = $(SRC)/operations.c \
             $(SRC)/chek.c \
             $(SRC)/ft_atoi.c \
             $(SRC)/ft_split.c \
             $(SRC)/indexer.c \
             $(SRC)/is_sorted.c \
             $(BONUS_SRC)/do_op.c \
             $(BONUS_SRC)/checker.c

OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
