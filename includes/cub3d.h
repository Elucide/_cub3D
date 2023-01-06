/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:39:36 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/06 20:06:17 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./garbage.h"
# include "./get_next_line.h"
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_img;

typedef struct s_data
{
	int		h;
	int		w;
	char	*path;
	int		fd;
	void	*mlx_ptr;
	void	*mlx_win;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor;
	int		ceiling;
	int		nb_el;
	float	player_pos_x;
	float	player_pos_y;
	float	ray_dir_x;
	float	ray_dir_y;
	float	speed;
	float	perpWallDist;
	float	camera_x;
//	float	camera_y;
	float	plane_x;
	float	plane_y;
	float	dir_x;
	float	dir_y;
	float	sideDistX;
	float	sideDistY;
	float	deltaDistX;
	float	deltaDistY;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	t_img	img;
	char	**map;
}			t_data;

t_data	*_data(void);
void 	parse(void);
int		main(int ac, char **av);
int		close_win(int param);
int		key_hook(int keycode, void *param);
void	img_pixel_put(int x, int y, int color);
int		mlx_push_img(void);
void	mlx_img_addr(void);
void	ft_free(void);
int		rgb_convert(int r, int g, int b);
int		render(void);
void	print_line(int len, int pos, int color);
char	*check_element(char *s);
void	parse_elements(void);
int		is_space(char c);
char	*store_element(char *element, char *s);
int		store_color(int element, char *s);
int		parse_color(char *s);
void	parse_map(void);

#endif
