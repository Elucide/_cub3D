/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:29:15 by yschecro          #+#    #+#             */
/*   Updated: 2023/01/11 16:09:21 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_line(int len, int pos, int color)
{
	int	i;
	t_data	*data;
	
	data = _data();
	dprintf(2, "pos is %d		color is %d		len is %d\n", pos, color, len);
	i = 0;
	while (i < len)
	{
		img_pixel_put(pos, data->h / 2 - (len / 2) + i, color);
		i++;
	}
}
