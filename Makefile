SRCS	=	srcs/main.c\
			srcs/parsing.c\
			srcs/hooks.c\
			includes/garbage.c\

INC		=	includes/cub3d.h

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -g3 -I includes/ 

MLX		=	mlx_linux

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

NAME	=	cub3d

MLX_MACOS =  -Lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(MLX) $(OBJS) $(INC) 
#		 make -C mlx_linux/
		 @$(MAKE) -C libft
		 @$(MAKE) -C mlx_linux
		 @echo "cub3d : libft compiled"
#		 $(CC) -g $(CFLAGS) -o $(NAME) $(OBJS) $(INC) libft/libft.a -Lmlx -I/usr/include -Imlx_linux -lXext -lX11 -lm -lz
		 $(CC) -g $(CFLAGS) -o $(NAME) $(OBJS) $(INC) libft/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
		 @echo "cub3d : compiled"

$(MLX):
#		cd mlx_linux && ./configure
#		@make -C mlx_linux/
		@echo "cub3d : minilibx compiled" 

macos:  $(OBJS)
		$(MAKE) -C libft
		@echo "cub3d : libft compiled"
		@$(CC) $(MLX_MACOS) $(CFLAGS) $^ minilibx_macos/libmlx.a libft/libft.a -o $(NAME)
		@echo "cub3d : compiled"
	
libft: 
		

clean:
		@$(MAKE) -C libft clean
		@$(RM) $(OBJS)
		make -C mlx_linux/ clean
		@echo "cub3d : objects has been erased"

fclean:	clean
		@$(MAKE) -C libft fclean
		@$(RM) $(NAME)
		@echo "cub3d : objects and name has been erased"

re: fclean all

test_leaks:
	valgrind $(NAME)

.PHONY: bonus all clean fclean re test_leaks
