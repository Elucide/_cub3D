/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:30:49 by yschecro          #+#    #+#             */
/*   Updated: 2023/03/03 03:28:36 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	up_down_hook(int keycode)
{
	t_data	*d;

	d = _data();
	if (keycode == 119)
	{
		if (d->map[(int)(d->player_pos_x + d->dir_x * \
					(d->speed * 2))][(int)(d->player_pos_y)] == '0')
			d->player_pos_x += d->dir_x * d->speed;
		if (d->map[(int)(d->player_pos_x)][(int)(d->player_pos_y \
					+ d->dir_y * (d->speed * 2))] == '0')
			d->player_pos_y += d->dir_y * d->speed;
		render();
	}
	if (keycode == 115)
	{
		if (d->map[(int)(d->player_pos_x - d->dir_x * (d->speed * \
						2))][(int)(d->player_pos_y)] == '0')
			d->player_pos_x -= d->dir_x * d->speed;
		if (d->map[(int)(d->player_pos_x)][(int)(d->player_pos_y - \
					d->dir_y * (d->speed * 2))] == '0')
			d->player_pos_y -= d->dir_y * d->speed;
		render();
	}
}

void	right_hook(int keycode)
{
	t_data	*d;
	float	v_orth_x;
	float	v_orth_y;

	d = _data();
	if (keycode == 97)
	{
		v_orth_x = -d->dir_y;
		v_orth_y = d->dir_x;
		if (d->map[(int)(d->player_pos_x + v_orth_x * \
					(d->speed * 2))][(int)(d->player_pos_y)] == '0')
			d->player_pos_x += v_orth_x * d->speed;
		if (d->map[(int)(d->player_pos_x)][(int)(d->player_pos_y + v_orth_y \
					* (d->speed * 2))] == '0')
			d->player_pos_y += v_orth_y * d->speed;
		render();
	}
}

void	left_hook(int keycode)
{
	t_data	*d;
	float	v_orth_x;
	float	v_orth_y;

	d = _data();
	if (keycode == 100)
	{
		v_orth_x = d->dir_y;
		v_orth_y = -d->dir_x;
		if (d->map[(int)(d->player_pos_x + v_orth_x * \
					(d->speed * 2))][(int)(d->player_pos_y)] == '0')
			d->player_pos_x += v_orth_x * d->speed;
		if (d->map[(int)(d->player_pos_x)][(int)(d->player_pos_y + \
					v_orth_y * (d->speed * 2))] == '0')
			d->player_pos_y += v_orth_y * d->speed;
		render();
	}
}

void	pan_hook(int keycode)
{
	t_data	*d;
	float	old_dir_x;
	float	old_plane_x;

	d = _data();
	old_dir_x = d->dir_x;
	old_plane_x = d->plane_x;
	if (keycode == 65363)
	{
		d->dir_x = d->dir_x * cos(-d->rs) - d->dir_y * sin(-d->rs);
		d->dir_y = old_dir_x * sin(-d->rs) + d->dir_y * cos(-d->rs);
		d->plane_x = d->plane_x * cos(-d->rs) - d->plane_y * sin(-d->rs);
		d->plane_y = old_plane_x * sin(-d->rs) + d->plane_y * cos(-d->rs);
		render();
	}
	if (keycode == 65361)
	{
		d->dir_x = d->dir_x * cos(d->rs) - d->dir_y * sin(d->rs);
		d->dir_y = old_dir_x * sin(d->rs) + d->dir_y * cos(d->rs);
		d->plane_x = d->plane_x * cos(d->rs) - d->plane_y * sin(d->rs);
		d->plane_y = old_plane_x * sin(d->rs) + d->plane_y * cos(d->rs);
		render();
	}
}

int	key_hook(int keycode, void *param)
{
	t_data	*d;

	d = _data();
	up_down_hook(keycode);
	right_hook(keycode);
	left_hook(keycode);
	pan_hook(keycode);
	if (keycode == 65307)
		close_win(0);
	if (keycode == 99)
	{
		if (d->img.img_ptr)
			mlx_destroy_image(d->mlx_ptr, d->img.img_ptr);
		d->img.img_ptr = mlx_xpm_file_to_image(d->mlx_ptr, \
				"./textures/signature.xpm", &d->w, &d->h);
		if (!d->img.img_ptr)
			print_error("Error\nFailed to create image\n");
		d->img.addr = mlx_get_data_addr(d->img.img_ptr, &d->img.bpp, \
				&d->img.len, &d->img.endian);
		mlx_put_image_to_window(d->mlx_ptr, d->mlx_win, d->img.img_ptr, 0, 0);
	}
	return ((void) param, 1);
}
