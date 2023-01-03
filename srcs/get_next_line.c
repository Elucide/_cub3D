/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:19:53 by rbenayou          #+#    #+#             */
/*   Updated: 2022/02/24 20:20:47 by rbenayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buff_crumbs;
	char		*result;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff_crumbs = ft_read(fd, buff_crumbs);
	if (buff_crumbs == NULL)
		return (NULL);
	result = ft_cut(buff_crumbs);
	buff_crumbs = ft_clean(buff_crumbs);
	return (result);
}

char	*ft_read(int fd, char *buff_crumbs)
{
	char	*buff;
	int		i;

	i = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	while (ft_strchr(buff_crumbs, '\n') == 0 && i > 0)
	{	
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
			return (free(buff), NULL);
		buff[i] = '\0';
		buff_crumbs = ft_strjoin(buff_crumbs, buff);
	}
	return (free(buff), buff_crumbs);
}

char	*ft_cut(char *buff_crumbs)
{
	char	*result;
	int		i;

	i = 0;
	if (!buff_crumbs[i])
		return (NULL);
	while (buff_crumbs[i] != '\n' && buff_crumbs[i])
		i++;
	result = malloc(sizeof(char) * i + 2);
	if (result == NULL)
		return (NULL);
	result[i + 1] = '\0';
	while (i >= 0)
	{
		result[i] = buff_crumbs[i];
		i--;
	}
	return (result);
}

char	*ft_clean(char *buff_crumbs)
{
	char	*buff_temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buff_crumbs[i] != '\n' && buff_crumbs[i])
		i++;
	if (!buff_crumbs[i])
		return (free(buff_crumbs), NULL);
	buff_temp = malloc(sizeof(char) * strlen(buff_crumbs) - i + 1);
	i++;
	while (buff_crumbs[i])
	{
		buff_temp[j] = buff_crumbs[i];
		i++;
		j++;
	}
	buff_temp[j] = '\0';
	free(buff_crumbs);
	return (buff_temp);
}
