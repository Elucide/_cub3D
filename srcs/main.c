/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:19:13 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/03 23:12:29 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_data	*_data(void)
{
	static t_data	data;

	return (&data);
}

int	init_mlx_ptr(void)
{
	_data()->mlx_ptr = mlx_init();
	if (!_data()->mlx_ptr)
		return (0);
	_data()->mlx_win = mlx_new_window(_data()->mlx_ptr, 1080, 720, "cub3d");
	if (!_data()->mlx_win)
		return (free(_data()->mlx_ptr), 0);
	return (1);
}

int	close_win(int param)
{
	t_data	*data;

	data = _data();
//	if (data->img.img_ptr)
//		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	exit(param);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data *data;

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
	init_mlx_ptr();
	mlx_hook(data->mlx_win, 17, 0, close_win, 0);
//	mlx_key_hook(data->mlx_win, close_win);
//	mlx_hook(data->mlx_win, 6, 1L << 8, julia_move, data->mlx_ptr);
	mlx_loop(data->mlx_ptr);	
}
