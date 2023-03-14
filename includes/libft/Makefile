
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror

# List source files.
LIB_CHECK = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \

LIB_CONVERT = ft_toupper.c \
			ft_tolower.c \
			ft_atoi.c \
			ft_itoa.c \

LIB_MEMORY = ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_calloc.c \

LIB_STRING = ft_strlcpy.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_split.c \
			ft_strtrim.c \

LIB_APPLY = ft_strmapi.c \
			ft_striteri.c \

LIB_FILE_DESCRIPTOR = ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \

LIB_LINKED_LIST = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \

LIB_GET_NEXT_LINE = get_next_line.c \
			get_next_line_utils.c \

LIB_FT_PRINTF = ft_printf_hex.c \
			ft_printf_unsigned.c \
			ft_printf_pointers.c \
			ft_printf_tools.c \
			ft_printf.c \

INC = inc
DIR_OBJ = obj

DIR_LIB_CHECK = lib_check
DIR_LIB_CONVERT = lib_convert
DIR_LIB_MEMORY = lib_memory
DIR_LIB_STRING = lib_string
DIR_LIB_APPLY = lib_apply
DIR_LIB_FILE_DESCRIPTOR = lib_file_descriptor
DIR_LIB_LINKED_LIST = lib_linked_list
DIR_LIB_GET_NEXT_LINE = ft_get_next_line
DIR_LIB_PRINTF = ft_printf

O_LIB_CHECK = $(LIB_CHECK:%.c=$(DIR_OBJ)/$(DIR_LIB_CHECK)/%.o)
O_LIB_CONVERT = $(LIB_CONVERT:%.c=$(DIR_OBJ)/$(DIR_LIB_CONVERT)/%.o)
O_LIB_MEMORY = $(LIB_MEMORY:%.c=$(DIR_OBJ)/$(DIR_LIB_MEMORY)/%.o)
O_LIB_STRING = $(LIB_STRING:%.c=$(DIR_OBJ)/$(DIR_LIB_STRING)/%.o)
O_LIB_APPLY = $(LIB_APPLY:%.c=$(DIR_OBJ)/$(DIR_LIB_APPLY)/%.o)
O_LIB_FILE_DESCRIPTOR = $(LIB_FILE_DESCRIPTOR:%.c=$(DIR_OBJ)/$(DIR_LIB_FILE_DESCRIPTOR)/%.o)
O_LIB_LINKED_LIST = $(LIB_LINKED_LIST:%.c=$(DIR_OBJ)/$(DIR_LIB_LINKED_LIST)/%.o)
O_LIB_GET_NEXT_LINE = $(LIB_GET_NEXT_LINE:%.c=$(DIR_OBJ)/$(DIR_LIB_GET_NEXT_LINE)/%.o)
O_LIB_PRINTF = $(LIB_FT_PRINTF:%.c=$(DIR_OBJ)/$(DIR_LIB_PRINTF)/%.o)


$(DIR_OBJ)/$(DIR_LIB_CHECK)/%.o: $(DIR_LIB_CHECK)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	$(COMPILE_MESSAGE)

$(DIR_OBJ)/$(DIR_LIB_CONVERT)/%.o: $(DIR_LIB_CONVERT)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	$(COMPILE_MESSAGE)

$(DIR_OBJ)/$(DIR_LIB_MEMORY)/%.o: $(DIR_LIB_MEMORY)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	$(COMPILE_MESSAGE)

$(DIR_OBJ)/$(DIR_LIB_STRING)/%.o: $(DIR_LIB_STRING)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	$(COMPILE_MESSAGE)

$(DIR_OBJ)/$(DIR_LIB_APPLY)/%.o: $(DIR_LIB_APPLY)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	$(COMPILE_MESSAGE)

$(DIR_OBJ)/$(DIR_LIB_FILE_DESCRIPTOR)/%.o: $(DIR_LIB_FILE_DESCRIPTOR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	$(COMPILE_MESSAGE)

$(DIR_OBJ)/$(DIR_LIB_LINKED_LIST)/%.o: $(DIR_LIB_LINKED_LIST)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	$(COMPILE_MESSAGE)

$(DIR_OBJ)/$(DIR_LIB_GET_NEXT_LINE)/%.o: $(DIR_LIB_GET_NEXT_LINE)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	$(COMPILE_MESSAGE)

$(DIR_OBJ)/$(DIR_LIB_PRINTF)/%.o: $(DIR_LIB_PRINTF)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	$(COMPILE_MESSAGE)

all: $(NAME)

$(NAME): $(O_LIB_CHECK) $(O_LIB_CONVERT) $(O_LIB_MEMORY) $(O_LIB_STRING) $(O_LIB_APPLY) $(O_LIB_FILE_DESCRIPTOR) $(O_LIB_LINKED_LIST) $(O_LIB_GET_NEXT_LINE) $(O_LIB_PRINTF)
	@$(AR) rcs $@ $^
	@ranlib $@

clean:
	@$(RM) -rf $(DIR_OBJ)
	$(MESSY_MESSAGE)
	$(DONE_MESSAGE)

fclean: clean
	@$(RM) $(NAME)
	$(MESSY_MESSAGE)
	$(DONE_MESSAGE)

re: fclean all
	$(EMPTY_MESSAGE)
	$(RESET_MESSAGE_3)
	$(RESET_MESSAGE_2)
	$(RESET_MESSAGE_1)

.PHONY: clean fclean re all
