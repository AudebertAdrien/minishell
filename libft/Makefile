NAME		= libft.a

CC			= gcc -g
CFLAGS		= -Wall -Wextra -Werror

SRCS		= ft_atoi.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_bzero.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_strcmp.c \
			ft_printf.c \
		  	ft_strlen.c \
		  	ft_printchar.c \
		  	ft_printstr.c \
		  	ft_printnbr_int.c \
		  	ft_printnbr_unsigned.c \
		  	ft_printnbr_base.c \
		  	ft_printnbr_ptr.c \

OBJS		= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -I. -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs ${NAME} ${OBJS} 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
