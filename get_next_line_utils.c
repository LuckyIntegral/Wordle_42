/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:10:58 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/10 23:23:59 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

int	ft_contains(char *set, char c)
{
	if (!set)
		return (0);
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	res;

	res = ft_strlen(src);
	if (!dst || !src || !size)
		return (res);
	while (*src && --size > 0)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (res);
}

char	*ft_strdup(const char *s1)
{
	char	*new;

	new = (char *)malloc(sizeof (char) * (ft_strlen(s1) + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, ft_strlen(s1) + 1);
	return (new);
}
