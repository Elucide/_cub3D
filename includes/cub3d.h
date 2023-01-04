/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:39:36 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/04 17:36:49 by yschecro         ###   ########.fr       */
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
	t_img	img;
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

#endif
