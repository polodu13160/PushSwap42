.PHONY = all clean fclean re
CC = cc
FLAGS = -Wall -Wextra -Werror -I $(PRINTF_DIR) -I $(PRINTF_DIR)/libft_updated
NAME = push_swap
SRCS = main.c
PRINTF_DIR = ./printf42lyon
PRINTF = $(PRINTF_DIR)/libftprintf.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)
%.o: %.c push_swap.h $(PRINTF)
	${CC} ${FLAGS} -c $< -o $@


$(PRINTF): ./printf42lyon/*.c ./printf42lyon/ft_printf.h
	$(MAKE) -C $(LIBFT_DIR)
$(NAME): $(LIBFT) $(OBJS) Makefile $(LIBFT_DIR)/Makefile
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: 
	${MAKE} fclean 
	${MAKE} all	







