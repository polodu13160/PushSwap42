.PHONY: all clean fclean re init

CC = cc
FLAGS = -Wall -Wextra -Werror -g3
# FLAGS = -Wall -Wextra -g3
NAME = push_swap
SRCS = main.c parsing.c parsing_pt2.c rules.c rules_pt2.c free.c algo.c algo_pt2.c
PRINTF_DIR = ./printf42lyon
PRINTF = $(PRINTF_DIR)/libftprintf.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF) Makefile
	$(CC) $(OBJS) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(PRINTF): 
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean


fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

init:
	$(MAKE) re
	$(MAKE) clean


