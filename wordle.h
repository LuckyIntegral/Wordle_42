/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:07:02 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/11 17:02:23 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_H
# define WORDLE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/time.h>

# define STDIN 0
# define GNL_BUFFER 8
# define TABLE_SIZE 4096

// error messages
# define MALLOC_FAIL "Error occured during aloc system call"
# define OPEN_FAIL "Error occured during open system call"
# define RANDOM_FAIL "Error occured during random call"

// modes for get next line function, passed as second argument for the function
# define READ 0
# define CLEAN 1

// return status value of the funcitons
# define SUCCESS 0
# define FAILURE 1

// mini boolean that allows you to make it more readable
# define TRUE 1
# define FALSE 0

// max attempts
# define MAX_ATTEMPTS 5

// for the hash code
typedef unsigned int	t_hash;

// binary tree, contains sorted data for hash table
// left is a pointer to the next node of the tree (smaller one, of course)
// right is a pointer to the next node of the tree (greater one, of course)
typedef struct s_list
{
	t_hash			hash;
	char			*value;
	struct s_list	*next;
}	t_list;

// hash table that contains binary trees
typedef struct s_hash_table
{
	t_list	**elements;
	size_t	size;
}	t_hash_table;

// randominette
char		*random_word(t_hash_table *database);

// get next line and utils
char		*get_next_line(int fd, int mode);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_contains(char *set, char c);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);

// parser part
int			parse_file(t_hash_table *table);

// function that makes hashcode for a string (for improved searching algo)
t_hash		hashcode(char *str);

// you know what it is, but you dont need it:)
char		ft_strcmp(char *s1, char *s2);

// for error handling
void		exit_program(char *status);

// table lib
int			table_contains(t_hash_table *table, char *value);
void		table_insert(t_hash_table *table, t_list *node);
void		table_destroy(t_hash_table *table);
int			table_init(t_hash_table *table);

// list lib
char		*list_get_value_by_index(t_list *list, int index);
int			list_contains(t_list *node, char *value, t_hash hash);
void		list_add_front(t_list **list, t_list *node);
t_list		*list_create(char *value);
void		list_clean(t_list *node);
int			list_size(t_list *list);

#endif
