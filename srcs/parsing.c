/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:00:10 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/03 23:13:35 by rbenayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_space(char c)
{
	if (c == '\t' || c == '\v' || c == '\n' || c == '\r' || c == '\f' || c == ' ') 
		return (1);
	return (0);
}

int	check_extension(char *path)
{
 	if (!ft_strcmp(ft_strnstr(path, ".cub", ft_strlen(path)), ".cub"))	
		return(1);
	return(0);
}

int	check_path(char *path)
{
	int	i;
	int	j;
	char	*tmp;

	i = 0;
	j = 0;
	while(path[i] && is_space(path[i]))
		i++;
	if (!path[i])
		return(0);
	while(path[i] && !is_space(path[i]))
	{
		j++;
		i++;
	}
	tmp = ft_substr(path, i - j, j);
	while(path[i] && is_space(path[i]))
	{
		if (path[i + 1] && is_space(path[i]) && !is_space(path[i + 1]))
			return(0);
		i++;
	}
	if (!check_extension(tmp))
		return (0);
	return(1);
}

void	parse_elements(void)
{
	/*t_data *data;

	data=_data();
*/ }

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
