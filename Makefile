SRCS	=	srcs/main.c\
			srcs/parsing.c\
			srcs/parsing_utils.c\
			srcs/parse_elements.c\
			srcs/parse_map.c\
			srcs/parse_player.c\
			srcs/store_elements.c\
			srcs/store_sprites.c\
			srcs/hooks.c\
			srcs/rendering.c\
			srcs/utils.c\
			srcs/split_map.c\
			srcs/rendering_utils.c\
			srcs/raycasting_utils.c\
			includes/garbage.c\
			includes/get_next_line.c\
			includes/get_next_line_utils.c\

INC		=	includes/cub3d.h

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I includes/ 

MLX		=	mlx_linux

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

NAME	=	cub3D

MLX_MACOS =  -Lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(MLX) $(OBJS) $(INC) 
#		 make -C mlx_linux/
		 @$(MAKE) -C libft
		 @$(MAKE) -C mlx_linux
		 @echo "cub3d : libft compiled"
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

.PHONY: bonus all clean fclean re
