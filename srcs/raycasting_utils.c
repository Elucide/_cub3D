/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:29:15 by yschecro          #+#    #+#             */
/*   Updated: 2023/01/04 18:37:53 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void	print_line(int dir, int len, int pos)
{
	int	i;
	t_data	*data;
	
	data = _data();
	i = 0;
	while (i < len)
	{
		img_pixel_put(pos, data->h / 2 - (len / 2) + i, 6512 + dir);
		i++;
	}
}
