/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frontend.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:13:46 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/11 23:19:16 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

void	print_header(void)
{
	printf("                                        $$\\ $$\\\n");
	printf("                                        $$ |$$ |\n");
	printf("$$\\  $$\\  $$\\  $$$$$$\\   $$$$$$\\   $$$$$$$ |$$ | $$$$$$\\\n");
	printf("$$ | $$ | $$ |$$  __$$\\ $$  __$$\\ $$  __$$ |$$ |$$  __$$\\ \n");
	printf("$$ | $$ | $$ |$$ /  $$ |$$ |  \\__|$$ /  $$ |$$ |$$$$$$$$ |\n");
	printf("$$ | $$ | $$ |$$ |  $$ |$$ |      $$ |  $$ |$$ |$$   ____|\n");
	printf("\\$$$$$\\$$$$  |\\$$$$$$  |$$ |      \\$$$$$$$ |$$ |\\$$$$$$$\\ \n");
	printf(" \\_____\\____/  \\______/ \\__|       \\_______|\\__| \\_______|\n");
	printf("\nThe rules part will be here soon!\n");
}

void	print_colorful_string(char *word, char *guess)
{
	int	colors[5] = {GRAY, GRAY, GRAY, GRAY, GRAY};

	for (int i = 0; i < 5; i++)
		if (guess[i] == word[i])
			colors[i] = GREEN;
	for (int i = 0; i < 5; i++)
	{
		if (!ft_contains(word, guess[i]) || colors[i] == GREEN)
			continue ;
		for (int j = 0; j < 5; j++)
			if (colors[j] == GRAY && word[j] == guess[i])
				colors[i] = YELLOW;
	}
	for (int i = 0; i < 5; i++)
	{
		switch (colors[i])
		{
			case (GRAY): put_gray(guess[i]);
				break;
			case (YELLOW): put_yellow(guess[i]);
				break ;
			case (GREEN): put_green(guess[i]);
		}
		printf("%c", i == 4 ? '\n' : ' ');
	}
}

int	is_valid(char *str)
{
	const unsigned long	len = strlen(str);

	if (len != WORD_LEN + 1)
		return (FALSE);
	for (int i = 0; i < 5; i++)
		if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))
			return (FALSE);
	return (TRUE);
}

int interact_player(t_hash_table *table, char *word)
{
	static char	*history[6] = {"_____", "_____", "_____", "_____", "_____", "_____"};
	char	*str = NULL;
	int		win = 0;
	int		i;

	i = 0;
	print_header();
	while (i < ATTEMPS)
	{
		str = get_next_line(STDIN, READ);
		if (!str)
			break ;
		if (is_valid(str))
		{
			str = trim_n_shift(str);
			if (table_contains(table, str))
			{
				history[i] = str;
				printf("\n");
				for (int j = 0; j <= i; j++)
					print_colorful_string(word, history[j]);
				for (int j = i; j < ATTEMPS - 1; j++)
					printf("_ _ _ _ _\n");
				printf("\n");
				i++;
				if (ft_strcmp(word, str) == 0)
				{
					win = 1;
					break ;
				}
			}
			else
				(free(str), printf("Word doesn't exist!\n"));
		}
		else
			(free(str), printf("Not a valid one\n"));
	}
	if (!win)
		printf("The word was %s\n", word);
	for (int j = 0; j < i; j++)
		free(history[j]);
	get_next_line(STDIN, CLEAN);
    return (SUCCESS);
}
