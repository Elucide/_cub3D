/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:30:49 by yschecro          #+#    #+#             */
/*   Updated: 2023/01/13 05:01:24 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_hook(int keycode, void *param)
{
	t_data	*data;

	data = _data();
	float	oldDirX = data->dir_x;
	float	oldPlaneX = data->plane_x;
	int		v_orth_x;
	int		v_orth_y;

	dprintf(2, "keycode is %d\n", keycode);
	if (keycode == 65307)
		close_win(0);
	if (keycode == 119)
	{
		if (data->map[(int)(data->player_pos_x + data->dir_x * data->speed)][(int)(data->player_pos_y)] == '0')
			data->player_pos_x += data->dir_x * data->speed;
		if (data->map[(int)(data->player_pos_x)][(int)(data->player_pos_y + data->dir_y * data->speed)] == '0')
			data->player_pos_y += data->dir_y * data->speed;
//		render();
	}
	if (keycode == 115)
	{
		if (data->map[(int)(data->player_pos_x - data->dir_x * data->speed)][(int)(data->player_pos_y)] == '0')
			data->player_pos_x -= data->dir_x * data->speed;
		if (data->map[(int)(data->player_pos_x)][(int)(data->player_pos_y - data->dir_y * data->speed)] == '0')
			data->player_pos_y -= data->dir_y * data->speed;
//		render();
	}
	if (keycode == 97)
	{
		v_orth_x = -data->dir_y;
		v_orth_y = data->dir_x;
		if (data->map[(int)(data->player_pos_x + v_orth_x * data->speed)][(int)(data->player_pos_y)] == '0')
			data->player_pos_x += v_orth_x * data->speed;
		if (data->map[(int)(data->player_pos_x)][(int)(data->player_pos_y + v_orth_y * data->speed)] == '0')
			data->player_pos_y += v_orth_y * data->speed;
		render();
	}
	if (keycode == 100)
	{
		if (data->map[(int)(data->player_pos_x - data->dir_x * data->speed)][(int)(data->player_pos_y)] == '0')
			data->player_pos_x -= data->dir_x * data->speed;
		if (data->map[(int)(data->player_pos_x)][(int)(data->player_pos_y - data->dir_y * data->speed)] == '0')
			data->player_pos_y -= data->dir_y * data->speed;
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
	return ((void) param, 1);
}
