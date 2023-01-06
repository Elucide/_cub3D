/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:29:15 by yschecro          #+#    #+#             */
/*   Updated: 2023/01/04 21:40:18 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_len(int pos)
{
	return (pos);
}

int	get_color(int pos)
{
	return (pos);
}

void	print_line(int pos)
{
	int	i;
	int	len;
	int	color;
	t_data	*data;
	
	data = _data();
	len = get_len(pos);
	color = get_color(pos);
	i = 0;
	while (i < len)
	{
		img_pixel_put(pos, data->h / 2 - (len / 2) + i, color);
		i++;
	}
}
