NAME	= so_long
LIBPRINTF	= printf
FILE = src/error_map.c src/so_long.c src/set_img.c \
		src/creating_window.c src/key_event.c \
		src/string_put.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rfv

OBJ = $(FILE:.c=.o)

all:		$(NAME)
			@echo "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
			norminette src && norminette include

$(NAME): $(OBJ)
			make -C $(LIBPRINTF)
			make -C minilibx-linux
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) printf/libftprintf.a -lX11 -lXext minilibx-linux/libmlx_Linux.a

clean:
			$(RM) -rf $(OBJ)
			make clean -C $(LIBPRINTF)
			make clean -C minilibx-linux

fclean:		clean
			$(RM) -f $(NAME)
			$(RM) -f $(LIBPRINTF)/libftprintf.a
			$(RM) -f $(LIBPRINTF)/libft/libft.a
			make clean -C minilibx-linux

re:		fclean all

.PHONY:		all clean fclean re