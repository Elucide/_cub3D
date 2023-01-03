/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenayou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:21:47 by rbenayou          #+#    #+#             */
/*   Updated: 2023/01/03 20:13:09 by rbenayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"

void	*ft_malloc(size_t size)
{
	t_garbage	*tmp;

	tmp = push_garbage(_garbage()->garbage, malloc(size));
	if (tmp == NULL)
	{
		free_garbage();
		return (NULL);
	}
	_garbage()->garbage = tmp;
	return (tmp->p);
}

t_garbage	*push_garbage(t_garbage *begin_list, void *data)
{
	t_garbage	*node_tmp;

	if (data == NULL)
		return (NULL);
	node_tmp = create_node(data);
	if (node_tmp == NULL)
	{
		free(data);
		return (NULL);
	}
	if (begin_list == NULL)
		return (node_tmp);
	else
	{
		node_tmp->next = begin_list;
		return (node_tmp);
	}
}

t_garbage	*create_node(void *data)
{
	t_garbage	*node;

	node = malloc(sizeof(t_garbage));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->p = data;
	return (node);
}

void	free_garbage(void)
{
	t_garbage	*garbage;
	t_garbage	*tmp;

	garbage = _garbage()->garbage;
	tmp = NULL;
	while (garbage)
	{
		tmp = garbage->next;
		free(garbage->p);
		free(garbage);
		garbage = tmp;
	}
	return (0);
}

t_garbage_data	*_garbage(void)
{
	static t_garbage_data	data;

	return (&data);
}
