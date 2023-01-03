/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:00:10 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/03 20:04:20 by rbenayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_path(char *path)
{
	//check si path valide
	return(0);
}
void 	parse(void)
{
	t_data *data;

	data=_data();
	if (check_path(data->path))
	{
		data->fd = open(data->path, O_RDONLY);
		if (data->fd < 0)
			break;
		//parse_elements();
		//parse_map();
		return;
	}
	printf("Error\nInvalid path\n");
	exit(EXIT_FAILURE);
}
