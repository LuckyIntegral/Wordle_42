/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 01:31:53 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/11 02:43:08 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

char	*trim_n_shift(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (i < 5)
		{
			str[i] = str[i] - 32;
			i++;
		}
		if (str[5])
			str[5] = '\0';
	}
	return (str);
}

int	parse_file(t_hash_table *table)
{
	const int		fd = open("words.txt", O_RDONLY);
	t_list			*list;
	char			*res;

	if (fd < 0)
		(free(table->elements), exit_program(OPEN_FAIL));
	while (1)
	{
		res = trim_n_shift(get_next_line(fd, READ));
		if (res == NULL)
			break ;
		list = list_create(res);
		if (list == NULL)
		{
			free(res);
			get_next_line(fd, CLEAN);
			table_destroy(table);
			exit_program(MALLOC_FAIL);
		}
		table_insert(table, list);
	}
	get_next_line(fd, CLEAN);
	close(fd);
	return (SUCCESS);
}
