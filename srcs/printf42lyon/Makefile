.PHONY = all clean fclean re
CC = cc
FLAGS = -Wall -Wextra -Werror -I $(LIBFT_DIR)
NAME = libftprintf.a
SRCS = ft_printf_format.c ft_printf.c ft_print_hexa.c
LIBFT_DIR = ./libft_updated
LIBFT = $(LIBFT_DIR)/libft.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c libftprintf.h $(LIBFT)
	${CC} ${FLAGS} -c $< -o $@


$(LIBFT): ./libft_updated/*.c ./libft_updated/libft.h
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS) Makefile $(LIBFT_DIR)/Makefile 
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)



clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
re: 
	${MAKE} fclean 
	${MAKE} all	






















