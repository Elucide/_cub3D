/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:30:49 by yschecro          #+#    #+#             */
/*   Updated: 2023/01/03 23:38:54 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_hook(int keycode, void *param)
{
	dprintf(2, "keycode is %d\n", keycode);
	if (keycode == 65307)
		close_win(0);
	return ((void) param, 1);
}
