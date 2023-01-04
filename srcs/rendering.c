/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:01:31 by yschecro          #+#    #+#             */
/*   Updated: 2023/01/04 18:38:13 by yschecro         ###   ########.fr       */
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
	dprintf(2, "setting ceiling and floor\n");
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
