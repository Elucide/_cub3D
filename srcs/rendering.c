/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:01:31 by yschecro          #+#    #+#             */
/*   Updated: 2023/01/04 17:29:25 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	set_floor_ceiling(void)
{
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
	mlx_push_img();
	return (0);
}
