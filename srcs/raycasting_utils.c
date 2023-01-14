/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:29:15 by yschecro          #+#    #+#             */
/*   Updated: 2023/01/14 04:59:53 by rbenayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	which_side(void)
{
	t_data	*data;

	data = _data();
	if (data->side && data->ray_dir_y > 0)
		return (0);
	else if (data->side && data->ray_dir_y < 0)
		return (1);
	else if (!data->side && data->ray_dir_x > 0)
		return (2);
	return (3);
}

int	**get_sprite(int nb)
{
	if (!nb)
		return (_data()->ea_sprite);
	if (nb == 1)
		return (_data()->we_sprite);
	if (nb == 2)
		return (_data()->so_sprite);
	return (_data()->no_sprite);
}

int	get_color(double y)
{
	t_data			*data;
	float			wall_x;
	unsigned long	tex_x;

	data = _data();
	if (!data->side)
		wall_x = data->player_pos_y + data->perp_dist * data->ray_dir_y;
	else
		wall_x = data->player_pos_x + data->perp_dist * data->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * 512);
	if ((!data->side && data->ray_dir_x > 0) || \
			(data->side && data->ray_dir_y < 0))
		tex_x = 512 - tex_x - 1;
	return (get_sprite(which_side())[(int)y][tex_x]);
}

void	print_line(int len, int pos)
{
	int		i;
	double	j;
	double	img_step;

	i = 0;
	j = 0;
	img_step = (double)512.0 / (double)len;
	j = img_step / 2;
	while (i < len)
	{
		img_pixel_put(pos, _data()->h / 2 - (len / 2) + i, get_color(j));
		i++;
		j += img_step;
	}
}
