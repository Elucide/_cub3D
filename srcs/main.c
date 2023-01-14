/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:19:13 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/14 02:02:11 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_data	*_data(void)
{
	static t_data	data;
	static int		init = 0;

	if (!init)
	{
		ft_bzero(&data, sizeof(t_data));
		ft_bzero(&data.img, sizeof(t_img));
		init = 1;
		data.ceiling = -1;
		data.floor = -1;
		data.fd = -1;
	}
	return (&data);
}

int	init_mlx_ptr(void)
{
	t_data	*data;

	data = _data();
	_data()->mlx_ptr = mlx_init();
	if (!_data()->mlx_ptr)
		return (0);
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->w, data->h, "cub3D");
	if (!_data()->mlx_win)
		return (free(_data()->mlx_ptr), 0);
	return (1);
}

int	close_win(int param)
{
	t_data	*data;

	data = _data();
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_garbage();
	exit(param);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = _data();
	if (argc == 2)
	{
		data->path = argv[1];
		parse();
	}
	else
	{
		printf("Error\nWrong number of arguments\n");
		return (1);
	}
	data->speed = 0.50;
	data->plane_x = -data->dir_y;
	data->plane_y = data->dir_x;
	data->rs = 0.25;
	render();
	mlx_hook(data->mlx_win, 17, 0, close_win, 0);
	mlx_key_hook (data->mlx_win, key_hook, data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
}
