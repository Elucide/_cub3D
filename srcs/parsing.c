/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:00:10 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/03 20:34:39 by rbenayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_space(char c)
{
	if (c == '\t' || c == '\v' || c == '\n' || c == '\r' || c == '\f' || c == ' ') 
		return (1);
	return (0);
}

int	check_path(char *path)
{
	int	i;

	i = 0;
	while(path[i] && is_space(path[i]))
		i++;
	if (!path[i])
		return(0);
	while(path[i] && !is_space(path[i]))
	{
		//check input
	}
	


	return(0);
}
void 	parse(void)
{
	t_data *data;

	data=_data();
	if (check_path(data->path))
	{
		data->fd = open(data->path, O_RDONLY);
		if (data->fd > 0)
		{
			//parse_elements();
			//parse_map();
			return;
		}
	}
	printf("Error\nInvalid path\n");
	exit(EXIT_FAILURE);
}
