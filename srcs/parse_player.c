/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:34:26 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/14 04:29:42 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_player(char pos, int x, int y)
{
	t_data	*data;

	data = _data();
	data->player_pos_x = x + 0.5;
	data->player_pos_y = y + 0.5;
	if (pos == 'E')
	{
		data->dir_x = 1;
		data->dir_y = 0;
	}
	if (pos == 'N')
	{
		data->dir_x = -1;
		data->dir_y = 0;
	}
	if (pos == 'W')
	{
		data->dir_x = 0;
		data->dir_y = -1;
	}
	if (pos == 'S')
	{
		data->dir_x = 1;
		data->dir_y = 0;
	}
}

void	check_pos(int i, int j)
{
	t_data	*data;

	data = _data();
	if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
		|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
	{
		if (data->dir_x == 0 && data->dir_y == 0)
		{
			init_player(data->map[i][j], i, j);
			data->map[i][j] = '0';
		}
		else
			print_error("Error\nOnly one player needed\n");
	}
}

void	check_player(void)
{
	int		i;
	int		j;
	t_data	*data;

	data = _data();
	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			check_pos(i, j);
			j++;
		}
		i++;
	}
	if (data->dir_x == 0 && data->dir_y == 0)
		print_error("Error\nNo player declaration\n");
}
