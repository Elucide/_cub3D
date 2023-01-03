SRCS	=	srcs/main.c\

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
		 @$(MAKE) -C libft
		 @echo "cub3d : libft compiled"
		 $(CC) -g $(CFLAGS) -o $(NAME) $(OBJS) $(INC) libft/libft.a -Lmlx -lmlx_Linux -lXext -lX11 -lm -lz
		 @echo "cub3d : compiled"

$(MLX):
		cd mlx && ./configure
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
		cd mlx && ./configure clean
		@echo "cub3d : objects has been erased"

fclean:	clean
		@$(MAKE) -C libft fclean
		@$(RM) $(NAME)
		@echo "cub3d : objects and name has been erased"

re: fclean all

test_leaks:
	valgrind $(NAME)

.PHONY: bonus all clean fclean re test_leaks
