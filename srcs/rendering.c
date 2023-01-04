/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:01:31 by yschecro          #+#    #+#             */
/*   Updated: 2023/01/04 20:51:38 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int	init_test_before_parsing(void)
{
	t_data *data = _data();
	data->player_pos_x = 4.0;
	data->player_pos_y = 4.0;
	data->camera_vector_x = 1;
	data->camera_vector_y = 0;
	data->map = ft_split("1111111111111111 1000000000000001	1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1111111111111111i", ' ');
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
	mlx_img_addr();
	set_floor_ceiling();
	print_line(0, 100, 360);
	print_line(0, 400, 400);
	mlx_push_img();
	return (0);
}
