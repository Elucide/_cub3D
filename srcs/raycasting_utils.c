/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:29:15 by yschecro          #+#    #+#             */
/*   Updated: 2023/01/13 09:22:41 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/*
void	print_line(int len, int pos, int color)
{
	int	i;
	t_data	*data;
	
	data = _data();
//	dprintf(2, "pos is %d		color is %d		len is %d\n", pos, color, len);
	i = 0;
	while (i < len)
	{
		img_pixel_put(pos, data->h / 2 - (len / 2) + i, color);
		i++;
	}
}
*/
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
//	if ((data->side && data->player_pos_x < data->map_x && \
		data->player_pos_y > data->map_y) || \
		(!data->side && data->player_pos_x < data->map_x && data->player_pos_y \
		< data->map_y))
		return (3);
	return (1);
}



float	iterator(int len, int image_height)
{
	if (image_height < len)
		return (len / image_height);
	else
		return (image_height / len);
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

int	get_color(int len, int i)
{
	t_data	*data;
	int		wall_x;
	int		tex_x;
	int		y;

	y = (int)(512 / len * i);
	data = _data();
	if (!data->side)
		wall_x = data->player_pos_y + data->perpWallDist * data->ray_dir_y;
	else
		wall_x = data->player_pos_x + data->perpWallDist * data->ray_dir_x;
	tex_x = (int)(wall_x * 512);
	if (!data->side && data->ray_dir_x > 0)
		tex_x = 512 - tex_x - 1;
	if (data->side && data->ray_dir_y < 0)
		tex_x = 512 - tex_x - 1;
	return (get_sprite(which_side())[y][tex_x]);
}

void	print_line(int len, int pos)
{
	int		i;
	int		j;
	t_data	*data;
	
	data = _data();
	i = 0;
	j = 0;
	while (i < len)
	{
		img_pixel_put(pos, data->h / 2 - (len / 2) + i, get_color(len, i));
		i++;
	}
}
