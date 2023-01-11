/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:30:49 by yschecro          #+#    #+#             */
/*   Updated: 2023/01/11 18:59:16 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_hook(int keycode, void *param)
{
	t_data	*data;

	data = _data();
	float oldDirX = data->dir_x;
	float oldPlaneX = data->plane_x;

	dprintf(2, "keycode is %d\n", keycode);
	if (keycode == 65307)
		close_win(0);
	if (keycode == 119)
	{
		_data()->player_pos_y += _data()->speed;
		render();
	}
	if (keycode == 115)
	{
		_data()->player_pos_y -= _data()->speed;
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
	if (keycode == 65363)
	{
		data->dir_x = data->dir_x * cos(data->rotSpeed) - data->dir_y * sin(data->rotSpeed);
		data->dir_y = oldDirX * sin(data->rotSpeed) + data->dir_y * cos(data->rotSpeed);
		data->plane_x = data->plane_x * cos(data->rotSpeed) - data->plane_y * sin(data->rotSpeed);
		data->plane_x = oldPlaneX * sin(data->rotSpeed) + data->plane_y * cos(data->rotSpeed);
		render();
	}
	if (keycode == 65361)
	{
		data->dir_x = data->dir_x * cos(data->rotSpeed) - data->dir_y * sin(data->rotSpeed);
		data->dir_y = oldDirX * sin(data->rotSpeed) + data->dir_y * cos(data->rotSpeed);
		data->plane_x = data->plane_x * cos(-data->rotSpeed) - data->plane_y * sin(data->rotSpeed);
		data->plane_x = oldPlaneX * sin(-data->rotSpeed) + data->plane_y * cos(data->rotSpeed);
		render();
	}

//	if (keycode == 104)
//		mlx_png_file_to_image(_data()->mlx_ptr, "./texture/signature.png", &)
	return ((void) param, 1);
}
