/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:19:13 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/03 22:22:57 by yschecro         ###   ########.fr       */
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
	_data()->mlx_ptr = mlx_new_window(_data()->mlx_ptr, 1080, 720, "cub3d");
	if (!_data()->mlx_ptr)
		return (free(_data()->mlx_ptr), 0);
	return (1);
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
	mlx_loop(data->mlx_ptr);
	
}
