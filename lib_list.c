/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:26:42 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/11 16:13:03 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

char	*list_get_value_by_index(t_list *list, int index)
{
	int	i;

	i = 0;
	while (i < index && list->next)
	{
		list = list->next;
		i++;
	}
	return (list->value);
}

int	list_size(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

//
int	list_contains(t_list *node, char *value, t_hash hash)
{
	while (node)
	{
		if (node->hash == hash)
		{
			if (ft_strcmp(node->value, value) == 0)
				return (TRUE);
		}
		node = node->next;
	}
	return (FALSE);
}

//
t_list	*list_create(char *value)
{
	t_list	*new;

	new = (t_list *)calloc(sizeof(*new), 1);
	if (new == NULL)
		return (NULL);
	new->hash = hashcode(value);
	new->value = value;
	new->next = NULL;
	return (new);
}

//
void	list_clean(t_list *node)
{
	t_list	*temp;

	while (node)
	{
		temp = node;
		node = node->next;
		free(temp->value);
		free(temp);
	}
}

//
void	list_add_front(t_list **list, t_list *node)
{
	if (*list != NULL)
		node->next = *list;
	*list = node;
}
