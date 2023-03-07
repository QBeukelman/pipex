# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: quentinbeukelman <quentinbeukelman@stud      +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/06 16:08:41 by quentinbeuk   #+#    #+#                  #
#    Updated: 2023/03/06 16:21:00 by quentinbeuk   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# ===== Names =====
NAME = pipex.a
NANE_EXCUITABLE = pipex


# ===== Compile =====
CC = gcc
CFLAGS = -I./INCLUDES  # -g -fsanitize=address


# ===== Colors =====
BOLD	:= \033[1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
RESET	:= \033[0m


# List source files.
SOURCES = pipex.c \

SOURCES_PROCESS = child_process.c \
			free_process.c \


# ===== Manage Directries =====
INC = inc
DIR_OBJ = obj

DIR_SOURCES = sources
DIR_SOURCES_PROCESS = sources/process

O_SOURCES = $(SOURCES:%.c=$(DIR_OBJ)/$(DIR_SOURCES)/%.o)
O_SOURCES_PROCESS = $(SOURCES_PROCESS:%.c=$(DIR_OBJ)/$(DIR_SOURCES_PROCESS)/%.o)

$(DIR_OBJ)/$(DIR_SOURCES)/%.o: $(DIR_SOURCES)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(DIR_OBJ)/$(DIR_SOURCES_PROCESS)/%.o: $(DIR_SOURCES_PROCESS)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@


# ===== Rules =====
all: $(NAME)

$(NAME): $(O_SOURCES) $(O_SOURCES_PROCESS)
	@echo "$(BLUE)$(BOLD)\nCompiling library: LIBFT ...$(RESET)"
	@$(MAKE) all -C ./includes/libft/
	@cp includes/libft/libft.a $(NAME)
	@mv $(NAME) $(DIR_SOURCES)
	@$(AR) rcs $@ $^
	@ranlib $@
	@echo "$(BLUE)$(BOLD)\nCompiling program: pipex ...$(RESET)"
	@rm $(NAME)
	@$(CC) -o $(NANE_EXCUITABLE) $(DIR_SOURCES)/$(SOURCES) $(DIR_SOURCES_PROCESS)/*.c $(DIR_SOURCES)/$(NAME)
	@echo "$(GREEN)$(BOLD)\nCompile sucessfull!\n$(RESET)"


clean:
	@echo "$(BLUE)\nCleaning ...$(RESET)"
	@$(RM) -rf $(DIR_OBJ)
	@$(MAKE) clean -C ./includes/libft/
	@rm -rf $(EXTRA_O)
	@rm -rf $(OBJS)
	@echo "$(GREEN)$(BOLD)\nAll clean!\n$(RESET)"

fclean: clean
	@rm -rf $(NANE_EXCUITABLE)
	@$(RM) $(DIR_SOURCES)/$(NAME)
	@$(MAKE) fclean -C ./includes/libft/

re: fclean all

.PHONY: clean fclean re all
