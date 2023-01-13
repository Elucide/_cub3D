/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:00:10 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/13 23:08:12 by rbenayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_space(char c)
{
	if (c == '\t' || c == '\v' || c == '\n' || c == '\r'
		|| c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	check_extension(char *path)
{
	if (!ft_strcmp(ft_strnstr(path, ".cub", ft_strlen(path)), ".cub"))
		return (1);
	return (0);
}

void	parse(void)
{
	t_data	*data;

	data = _data();
	data->path = check_element(data->path);
	if (data->path != NULL && check_extension(data->path))
	{
		data->fd = open(data->path, O_RDONLY);
		if (data->fd > 0)
		{
			parse_elements();
			parse_map();
			store_sprites();
			return ;
		}
	}
	print_error("Error\nInvalid path\n");
}
