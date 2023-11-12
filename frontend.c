/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frontend.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:13:46 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/12 13:45:55 by vfrants          ###   ########.fr       */
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
	int	checked[5] = {FALSE, FALSE, FALSE, FALSE, FALSE};

	for (int i = 0; i < 5; i++)
		if (guess[i] == word[i])
		{
			colors[i] = GREEN;
			checked[i] = TRUE;
		}
	for (int i = 0; i < 5; i++)
	{
		if (!ft_contains(word, guess[i]) || colors[i] == GREEN)
			continue ;

		for (int j = 0; j < 5; j++)
			if (colors[j] == GRAY && word[j] == guess[i] && checked[j] == FALSE)
			{
				colors[i] = YELLOW;
				checked[j] = TRUE;
			}
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
	printf("Test string: %s\n", word);
	while (i < MAX_ATTEMPTS)
	{
		write(0, "Put your word here! ", 20);
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
				for (int j = i; j < MAX_ATTEMPTS - 1; j++)
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
				(free(str), printf("\n\033[1;31mWord doesn't exist!\033[0m\nPlease make sure that the input is correct\n\n"));
		}
		else
			(free(str), printf("\nNot a valid one!\nPlease make sure that the word contains only \033[1;31m FIVE ALPHABETIC \033[0m characters\n\n"));
	}
	if (!win)
		printf("You lost, the word was \033[1;31m %s \033[0m 😓\nBetter luck net time!\n\n", word);
	else
	 	printf("🥳️ 🥳️ 🥳️\033[1;32mCongratulations, you won the game!!! 🥳️ 🥳️ 🥳️\033[0m\n\n");
	for (int j = 0; j < i; j++)
		free(history[j]);
	get_next_line(STDIN, CLEAN);
    return (SUCCESS);
}
