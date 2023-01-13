/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:01:31 by yschecro          #+#    #+#             */
/*   Updated: 2023/01/13 05:45:41 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void ft_print_tab(char **str)
{
	int i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	return ;
}

int	set_floor_ceiling(void)
{
	t_data	*data;
	int		x;
	int		y;

	data = _data();
	x = 0;
	y = 0;
	while (x < data->w)
	{
		y = 0;
		while(y < data->h)
		{
			if (y < data->h / 2)
				img_pixel_put(x, y, data->ceiling);
			else
				img_pixel_put(x, y, data->floor);
			y++;
		}
		x++;
	}
	return (1);
}

int	raycasting(void)
{
	t_data	*data;
	int		x;
	int		lineHeight;
	int		color;

	x = 0;
	data = _data();
	dprintf(2, "JOUEUR EN POSITION (%f; %f)\n", data->player_pos_x, data->player_pos_y);
	while (x < data->w)
	{
		data->camera_x = 2 * x / (float)data->w - 1;
//		dprintf(2, "camera_x is %f\n", data->camera_x);
		data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
		data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
		data->map_x = (int)data->player_pos_x;
		data->map_y = (int)data->player_pos_y;
		data->deltaDistX = (data->ray_dir_x == 0) ? 1e30 : fabs(1 / data->ray_dir_x);
		data->deltaDistY = (data->ray_dir_y == 0) ? 1e30 : fabs(1 / data->ray_dir_y);
		
//		data->deltaDistX = fabs(1 / data->ray_dir_x);
//		data->deltaDistY = fabs(1 / data->ray_dir_y);
		data->hit = 0;
//		dprintf(2, "data->DelatDistX = %f,    data->DeltaDistY = %f\n", data->deltaDistX, data->deltaDistY);
		if(data->ray_dir_x < 0)
		{
			data->step_x = -1;
			data->sideDistX = (data->player_pos_x - data->map_x) * data->deltaDistX;
		}
		else
		{
			data->step_x = 1;
			data->sideDistX = (data->map_x + 1.0 - data->player_pos_x) * data->deltaDistX;
		}
		if(data->ray_dir_y < 0)
		{
			data->step_y = -1;
			data->sideDistY = (data->player_pos_y - data->map_y) * data->deltaDistY;
		}
		else
		{
			data->step_y = 1;
			data->sideDistY = (data->map_y + 1.0 - data->player_pos_y) * data->deltaDistY;
		}
//		dprintf(2, "data->sideDistX = %f,    data->sideDistY = %f\n", data->sideDistX, data->deltaDistY);
		while (!data->hit)
		{
			if(data->sideDistX < data->sideDistY)
			{
				data->sideDistX += data->deltaDistX;
				data->map_x += data->step_x;
				data->side = 0;
			}
			else
			{
				data->sideDistY += data->deltaDistY;
				data->map_y += data->step_y;
				data->side = 1;
			}
//			dprintf(2, "map_x = %d       map_y = %d\n", data->map_x, data->map_y);
			if (data->map[data->map_x][data->map_y] == '1')
			{
				data->hit = 1;
			}
		}

		if (data->side == 0)
			data->perpWallDist = (data->sideDistX - data->deltaDistX);
		else
			data->perpWallDist = (data->sideDistY - data->deltaDistY);

		lineHeight = (int)((data->h / 1.5) / data->perpWallDist);
//		dprintf(2, "line len is %d, perpWallDist is %f\n", lineHeight, data->perpWallDist);
		color = rgb_convert(45, 200, 122);
		if (data->side == 1)
			color /= 2;
		//		color = 0;
		print_line(lineHeight, x, color);
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
