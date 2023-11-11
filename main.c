/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:09:56 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/11 02:44:29 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

int	main(void)
{
	t_hash_table	database;

	if (table_init(&database) == FAILURE)
		exit_program(MALLOC_FAIL);
	parse_file(&database);

	printf("Test 1 for hello %d\n", table_contains(&database, "HELLO"));
	printf("Test 2 for hello %d\n", table_contains(&database, "WORLD"));
	printf("Test 3 for hello %d\n", table_contains(&database, "SASKE"));

	table_destroy(&database);
	return (SUCCESS);
}
