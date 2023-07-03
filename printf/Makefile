NAME		= libftprintf.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC			= ft_printf.c \
		  		ft_strlen.c \
		  		ft_printchar.c \
		  		ft_printstr.c \
		  		ft_printnbr_int.c \
		  		ft_printnbr_unsigned.c \
		  		ft_printnbr_base.c \
		  		ft_printnbr_ptr.c \

OBJS		= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -I ./include -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
