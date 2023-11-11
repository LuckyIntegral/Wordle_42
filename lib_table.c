/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:27:14 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/11 01:31:39 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

t_hash	hashcode(char *str)
{
	t_hash	hash_value;

	hash_value = 0;
	while (*str)
		hash_value = hash_value * 31 + *str++;
	return (hash_value);
}

int	table_init(t_hash_table *table)
{
	table->size = TABLE_SIZE;
	table->elements = (t_list **)calloc(sizeof(t_list *), TABLE_SIZE);
	if (table->elements == NULL)
		return (FAILURE);
	return (SUCCESS);
}

void	table_destroy(t_hash_table *table)
{
	while (table->size--)
		list_clean(table->elements[table->size]);
	free(table->elements);
}

int	table_contains(t_hash_table *table, char *value)
{
	t_list	*node;
	t_hash	hash;

	hash = hashcode(value);
	node = table->elements[hash % table->size];
	if (node == NULL)
		return (FALSE);
	return (list_contains(node, value, hash));
}

void	table_insert(t_hash_table *table, t_list *new)
{
	list_add_front(&table->elements[new->hash % table->size], new);
}
