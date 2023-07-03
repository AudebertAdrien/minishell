MAIN		= minishell

CC			= gcc -g
CFLAGS		= -Wall -Wextra

VPATH		= src

SRCS		= main.c \
			  display_prompt.c \
			  parse_readline.c \
			  find_cmd.c \
			  echo.c \

INC			= -I./include -I./libft -I./printf
LIBFT		= -Llibft -lft 
PRINTF		= -Lprintf -lftprintf

OBJ			= $(addprefix obj/, $(SRCS:.c=.o))

obj/%.o: src/%.c 
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all: create_obj_dir $(MAIN) 

create_obj_dir :
	@mkdir -p obj

create_libs:
	@echo ✅ "Compile libft\n"
	@make re -s -C ./libft
	@echo ✅ "Compile ft_printf\n"
	@make re -s -C ./printf

$(MAIN): $(OBJ)
	@echo ✅ "Compile minishell\n"
	@$(CC) $^ -o $@ -lreadline $(INC) $(LIBFT) $(PRINTF)

clean_libs:
	@echo ✅ "Clean libft\n"
	@make fclean -s -C ./libft
	@echo ✅ "Clean ft_printf\n"
	@make fclean -s -C ./printf
	
clean: 
	@echo ✅ "Clean minishell\n"
	@rm -rf $(OBJ)
	@rm -rf obj/

fclean: clean
	@rm -f $(MAIN)

re: fclean all

.PHONY: all clean fclean re \
	create_directory \
	clean_lib \

