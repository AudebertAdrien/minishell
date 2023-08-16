MAIN		= minishell

CC		= gcc -g
CFLAGS		= -Wall -Wextra

VPATH		= src

SRCS		= main.c \
		  display_prompt.c \
		  parse_readline.c \
		  find_cmd.c \
		  echo.c \
		  cd.c \
		  pwd.c \
		  env.c \
		  utils.c \
		  exit.c \
		  export.c \
		  export_no_args.c \
		  unset.c \
		  redirection.c \

INC		= -I./include -I./libft -I./printf
LIBFT		= -Llibft -lft 
PRINTF		= -Lprintf -lftprintf

OBJ_DIR		= obj
OBJ		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all: create_obj_dir $(MAIN) 

create_obj_dir :
	@mkdir -p obj

create_libs:
	@echo ✅ "Compile libft\n"
	@make re -s -C ./libft
	@echo ✅ "Compile printf\n"
	@make re -s -C ./printf

$(MAIN): $(OBJ)
	@echo ✅ "Compile minishell\n"
	@$(CC) $^ -o $@ -lreadline $(INC) $(LIBFT) $(PRINTF)

clean_libs:
	@echo ✅ "Clean libft\n"
	@make fclean -s -C ./libft
	@echo ✅ "Clean printf\n"
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
