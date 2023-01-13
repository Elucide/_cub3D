/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:36:00 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/12 23:33:17 by rbenayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*store_element(char *element, char *s)
{
	t_data	*data;

	data = _data();
	if (element != NULL)
		print_error("Error\nDouble declaration\n");
	s += 2;
	data->nb_el++;
	return (check_element(s));
}

int	store_color(int element, char *s)
{
	t_data	*data;

	data = _data();
	if (element > 0)
		print_error("Error\nDouble declaration\n");
	s += 1;
	s = check_element(s);
	data->nb_el++;
	return (parse_color(s));
}

void	store_map(void)
{
	t_data	*data;
	char	*tmp_join;
	char	*tmp;
	int		i;

	data = _data();
	tmp_join = NULL;
	while (1)
	{
		i = 0;
		tmp = get_next_line(data->fd);
		if (tmp == NULL)
			print_error("Error\nNo map in file\n");
		while (tmp[i] && is_space(tmp[i]))
			i++;
		if (tmp[i])
			break ;
	}
	while (tmp != NULL)
	{
		tmp_join = ft_strjoin(tmp_join, tmp);
		tmp = get_next_line(data->fd);
	}
	data->map = split_map(tmp_join, '\n');
}
