/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:55:09 by yschecro          #+#    #+#             */
/*   Updated: 2023/01/03 18:56:37 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*to_find;

	to_find = (char *)needle;
	str = (char *)haystack;
	i = 0;
	if (!needle[0])
		return (str);
	while (i < len && haystack[i])
	{
		j = 0;
		while (str[i + j] && to_find[j] && i + j < len
			&& str[i + j] == to_find[j])
			j++;
		if (!needle[j])
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
