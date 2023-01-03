/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:19:13 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/03 19:49:03 by rbenayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_data	*_data(void)
{
	static t_data	data;

	return (&data);
}

int	main(int argc, char **argv)
{
	t_data *data;

	data=_data();
	if (argc == 2)
	{
		data->path = argv[1];
		parse();
	}
	else
	{
		printf("Error\nWrong number of arguments\n");
		return (1);
	}
}
