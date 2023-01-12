/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:36:00 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/12 22:06:52 by rbenayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*store_element(char *element, char *s)
{
	t_data	*data;

	data = _data();
	if (element != NULL)
	{
		printf("Error\nDouble declaration\n");
		free_garbage();
	}
	s += 2;
	data->nb_el++;
	return (check_element(s));
}

int	store_color(int element, char *s)
{
	t_data	*data;

	data = _data();
	if (element > 0)
	{
		printf("Error\nDouble declaration\n");
		free_garbage();
	}
	s += 1;
	s = check_element(s);
	data->nb_el++;
	return (parse_color(s));
}
