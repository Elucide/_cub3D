/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:25:56 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/12 18:32:52 by rbenayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*format_split(char *s)
{
	int		i;

	while (1)
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == '\n')
				break ;
			if (is_space(s[i]))
				i++;
			else
				break ;
		}
		if (s[i] == '\n')
		{
			while (i >= 0)
			{
				s++;
				i--;
			}
		}
		else
			return (s);
	}
}
