/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:01:31 by yschecro          #+#    #+#             */
/*   Updated: 2023/01/14 02:40:07 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_variables(int x)
{
	t_data	*data;

	data = _data();
	data->camera_x = 2 * x / (float)data->w - 1;
	data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
	data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
	data->map_x = (int)data->player_pos_x;
	data->map_y = (int)data->player_pos_y;
	if (!data->ray_dir_x)
		data->d_dist_x = 1e30;
	else
		data->d_dist_x = fabs(1 / data->ray_dir_x);
	if (!data->ray_dir_y)
		data->d_dist_y = 1e30;
	else
		data->d_dist_y = fabs(1 / data->ray_dir_y);
	data->hit = 0;
}

void	get_distances(void)
{
	t_data	*data;

	data = _data();
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->s_dist_x = (data->player_pos_x - data->map_x) * data->d_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->s_dist_x = (data->map_x + 1.0
				- data->player_pos_x) * data->d_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->s_dist_y = (data->player_pos_y - data->map_y) * data->d_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->s_dist_y
			= (data->map_y + 1.0 - data->player_pos_y) * data->d_dist_y;
	}
}

void	casting_ray(void)
{
	t_data	*data;

	data = _data();
	while (!data->hit)
	{
		if (data->s_dist_x < data->s_dist_y)
		{
			data->s_dist_x += data->d_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->s_dist_y += data->d_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->map[data->map_x][data->map_y] == '1')
			data->hit = 1;
	}
}

int	raycasting(void)
{
	t_data	*data;
	int		x;
	int		line_height;
	int		color;

	x = 0;
	data = _data();
	while (x < data->w)
	{
		init_variables(x);
		get_distances();
		casting_ray();
		if (data->side == 0)
			data->perp_dist = (data->s_dist_x - data->d_dist_x);
		else
			data->perp_dist = (data->s_dist_y - data->d_dist_y);
		line_height = (int)((data->h / 1.5) / data->perp_dist);
		color = rgb_convert(45, 200, 122);
		if (data->side == 1)
			color /= 2;
		print_line(line_height, x);
		x++;
	}
	return (1);
}

int	render(void)
{
	t_data	*data;

	data = _data();
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, data->w, data->h);
	if (!data->img.img_ptr)
		return (-1);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp, \
			&data->img.len, &data->img.endian);
	set_floor_ceiling();
	raycasting();
	mlx_push_img();
	return (0);
}
