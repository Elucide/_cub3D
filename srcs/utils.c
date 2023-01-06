/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:14:28 by yschecro          #+#    #+#             */
/*   Updated: 2023/01/06 20:03:48 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	rgb_convert(int r, int g, int b)
{
	return (r << 16) | (g << 8) | b;
}

void	img_pixel_put(int x, int y, int color)
{
	char	*pixel;
	t_data	*data;

	data = _data();
//	dprintf(1, "color is %d\n", color);
//	color = 0;
	if (x > 0 && x < data->w && y > 0 && y < data->h)
	{
		pixel = data->img.addr + (y * data->img.len + x * (data->img.bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

int	mlx_push_img(void)
{
	int		i;
	t_data	*d;

	d = _data();
	i = mlx_put_image_to_window(d->mlx_ptr, d->mlx_win, d->img.img_ptr, 0, 0);
	return (i);
}

void	mlx_img_addr(void)
{
	t_data	*d;

	d = _data();
	d->img.addr = mlx_get_data_addr(d->img.img_ptr, &d->img.bpp, \
			&d->img.len, &d->img.endian);
}

void	ft_free(void)
{
	t_data	*data;

	data = _data();
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	free(data->img.addr);
}
