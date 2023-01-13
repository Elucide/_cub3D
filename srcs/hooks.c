/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:30:49 by yschecro          #+#    #+#             */
/*   Updated: 2023/01/13 04:29:14 by rbenayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_hook(int keycode, void *param)
{
	t_data	*data;

	data = _data();
	float oldDirX = data->dir_x;
	float oldPlaneX = data->plane_x;

//	dprintf(2, "keycode is %d\n", keycode);
	if (keycode == 65307)
		close_win(0);
	if (keycode == 119)
	{
		if (data->map[(int)(data->player_pos_x + data->dir_x * data->speed)][(int)(data->player_pos_y)] == '0')
			data->player_pos_x += data->dir_x * data->speed;
		if (data->map[(int)(data->player_pos_x)][(int)(data->player_pos_y + data->dir_y * data->speed)] == '0')
			data->player_pos_y += data->dir_y * data->speed;
		render();
	}
	if (keycode == 115)
	{
		if (data->map[(int)(data->player_pos_x - data->dir_x * data->speed)][(int)(data->player_pos_y)] == '0')
			data->player_pos_x -= data->dir_x * data->speed;
		if (data->map[(int)(data->player_pos_x)][(int)(data->player_pos_y - data->dir_y * data->speed)] == '0')
			data->player_pos_y -= data->dir_y * data->speed;
		render();
	}
	if (keycode == 97)
	{
		_data()->player_pos_x -= _data()->speed;
		render();
	}
	if (keycode == 100)
	{
		_data()->player_pos_x += _data()->speed;
		render();
	}
	if (keycode == 65361)
	{
		data->dir_x = data->dir_x * cos(-data->rotSpeed) - data->dir_y * sin(-data->rotSpeed);
		data->dir_y = oldDirX * sin(-data->rotSpeed) + data->dir_y * cos(-data->rotSpeed);
		data->plane_x = data->plane_x * cos(-data->rotSpeed) - data->plane_y * sin(-data->rotSpeed);
		data->plane_y = oldPlaneX * sin(-data->rotSpeed) + data->plane_y * cos(-data->rotSpeed);
		render();
	}
	if (keycode == 65363)
	{
		data->dir_x = data->dir_x * cos(data->rotSpeed) - data->dir_y * sin(data->rotSpeed);
		data->dir_y = oldDirX * sin(data->rotSpeed) + data->dir_y * cos(data->rotSpeed);
		data->plane_x = data->plane_x * cos(data->rotSpeed) - data->plane_y * sin(data->rotSpeed);
		data->plane_y = oldPlaneX * sin(data->rotSpeed) + data->plane_y * cos(data->rotSpeed);
		render();
	}
	int w = data->w;
	int h = data->h;
	if (keycode == 99)
	{
		if (data->img.img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		data->img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/signature.xpm", &w, &h);	
		if (!data->img.img_ptr)
			print_error("Error\nFailed to create image\n");
		data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp, \
				&data->img.len, &data->img.endian);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0, 0);
	}
	return ((void) param, 1);
}
