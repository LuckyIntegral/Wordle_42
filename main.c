/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:09:56 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/11 18:17:46 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

int	main(void)
{
	t_hash_table	database;
	char			*word;

	if (table_init(&database) == FAILURE)
		exit_program(MALLOC_FAIL);
	parse_file(&database);
	word = random_word(&database);
	if (word == NULL)
	{
		table_destroy(&database);
		exit_program(RANDOM_FAIL);
	}
	interact_player(&database, word);

	table_destroy(&database);
	return (SUCCESS);
}
