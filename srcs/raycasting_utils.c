/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:29:15 by yschecro          #+#    #+#             */
/*   Updated: 2023/01/14 00:28:05 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	which_side(void)
{
	t_data *data;

	data = _data();
	if ((data->side && data->player_pos_x > data->map_x && \
		data->player_pos_y > data->map_y) || \
		(!data->side && data->player_pos_x < data->map_x && data->player_pos_y \
		> data->map_y))
		return (0);
	else if ((data->side && data->player_pos_x < data->map_x && \
		data->player_pos_y < data->map_y) || \
		(!data->side && data->player_pos_x > data->map_x && data->player_pos_y \
		< data->map_y))
		return (1);
	else if ((data->side && data->player_pos_x > data->map_x && \
		data->player_pos_y < data->map_y) || \
		(!data->side && data->player_pos_x > data->map_x && data->player_pos_y \
		> data->map_y))
		return (2);
/*	if ((data->side && data->player_pos_x < data->map_x && \
		data->player_pos_y > data->map_y) || \
		(!data->side && data->player_pos_x < data->map_x && data->player_pos_y \
		< data->map_y))*/
	return (3);
}

int	**get_sprite(int nb)
{
	if (!nb)
		return (_data()->no_sprite);
	if (nb == 1)
		return (_data()->so_sprite);
	if (nb == 2)
		return (_data()->we_sprite);
	return (_data()->ea_sprite);
}

int	get_y(int len, int i)
{
	return (512 / len * i);
}
/*
int	get_color(int len, int i, float img_step, float, i_step)
{
	t_data			*data;
	float			wall_x;
	unsigned long	tex_x;
	unsigned int	y;

	y = get_y(len, i);
	data = _data();
	if (!data->side)
		wall_x = data->player_pos_y + data->perpWallDist * data->ray_dir_y;
	else
		wall_x = data->player_pos_x + data->perpWallDist * data->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * 512);
	if ((!data->side && data->ray_dir_x > 0) || \
			(data->side && data->ray_dir_y < 0))
		tex_x = 512 - tex_x - 1;
	tex_x = 512 - tex_x;
	return (get_sprite(which_side())[y][tex_x]);
}
*/

int	get_color(double y)
{
	t_data	*data;
	float			wall_x;
	unsigned long	tex_x;

	data = _data();
	if (!data->side)
		wall_x = data->player_pos_y + data->perpWallDist * data->ray_dir_y;
	else
		wall_x = data->player_pos_x + data->perpWallDist * data->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * 512);
	if ((!data->side && data->ray_dir_x > 0) || \
			(data->side && data->ray_dir_y < 0))
		tex_x = 512 - tex_x - 1;
	tex_x = 511 - tex_x;
	return (get_sprite(which_side())[(int)y][tex_x]);
}

void	len_under_size(int len, int pos)
{
	int	i;
	double	j;
	double img_step;

	i = 0;
	j = 0;
//	dprintf(2, "len is %d    512 / len is %f\n", len, (double)512.0 / (double)len);
	img_step = (double)512.0 / (double)len;
//	img_step = 1;
	j = img_step / 2;
	while (i < len)
	{
		img_pixel_put(pos, _data()->h / 2 - (len / 2) + i, get_color(j));
		i++;
		j += img_step;
	}
}

void	print_line(int len, int pos)
{
//	int		i;
//	t_data	*data;
//	
//	data = _data();
//	i = 0;
/*	while (i < len)
	{
		img_pixel_put(pos, data->h / 2 - (len / 2) + i, get_color(len, i));
		i += 1;
	}*/
//	if (len < 512)
		len_under_size(len, pos);
}
