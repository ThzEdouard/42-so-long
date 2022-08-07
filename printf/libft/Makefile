#				//NAME AND COMPILATION\\ #
NAME		= libft.a

SRC_DIR		= ./
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I.
RM			= rm -f
AR			= ar rcs
#					//SOUCES\\  #
SRC_FT_CONV	= ft_conv/
FT_CONV = ft_atoi ft_itoa

SRC_FT_IS = ft_is/
FT_IS = ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_tolower ft_toupper

SRC_FT_MEM = ft_mem/
FT_MEN = ft_bzero ft_calloc ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset

SRC_FT_PUT = ft_put/
FT_PUT = ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd

SRC_FT_STR = ft_str/
FT_STR =  ft_split ft_strchr ft_strdup ft_striteri ft_strjoin ft_strlcat ft_strlcpy ft_strlen \
		ft_strmapi ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr

#				//ADD TO SRC_DIR\\#
SRC_FILES+=$(addprefix $(SRC_FT_CONV),$(FT_CONV))
SRC_FILES+=$(addprefix $(SRC_FT_IS),$(FT_IS))
SRC_FILES+=$(addprefix $(SRC_FT_MEM),$(FT_MEN))
SRC_FILES+=$(addprefix $(SRC_FT_STR),$(FT_STR))
SRC_FILES+=$(addprefix $(SRC_FT_PUT),$(FT_PUT))


SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		=	.cache_exists

all:		$(NAME)
			@echo "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(SRC_FT_CONV)
			@mkdir -p $(OBJ_DIR)$(SRC_FT_IS)
			@mkdir -p $(OBJ_DIR)$(SRC_FT_STR)
			@mkdir -p $(OBJ_DIR)$(SRC_FT_MEM)
			@mkdir -p $(OBJ_DIR)$(SRC_FT_PUT)


clean:
			@$(RM) -rf $(OBJ_DIR)

fclean:		clean
			@$(RM) -f $(NAME)

re:		fclean all


.PHONY:		all clean fclean re