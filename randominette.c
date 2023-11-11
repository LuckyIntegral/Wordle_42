/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randominette.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:00:46 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/11 16:41:39 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

char	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

static int	random_number(int range)
{
	struct timeval	time;
	int				result;

	gettimeofday(&time, NULL);
	result = time.tv_usec % range;
	// printf("rand number result %d, range %d\n", result, range);
	return (result);
}

char	*random_word(t_hash_table *database)
{
	t_list	*list;
	char	*word;
	int		size;

	list = NULL;
	for (int i = 0; list == NULL && i < 10; i++)
		list = database->elements[random_number(database->size)];
	if (list == NULL)
		return (NULL);
	size = list_size(list);
	if (!size)
		return (NULL);
	word = list_get_value_by_index(list , random_number(size));
	return (word);
}
