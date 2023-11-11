/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:09:56 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/11 17:10:55 by vfrants          ###   ########.fr       */
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
}

int	frontend(int argc, int **guess)
{
	int		attempts = 0;

	printf("Hello Wordle!\n");

	if(table_contains(guess) != 1)
	{
		printf("Try a different word!"); //error message
	}
	else 
	{
		while(attempts < MAX_ATTEMPTS)
		{
			printf("Enter your guess: ");
			scanf("%s", guess);

			//compare to answer word
			for (int i = 0; i < strlen(word); i++)
			{
				if (strcmp(guess, word) == 0)
				{
            		printf("Congratulations! You guessed the word correctly.\n");
            		break;
        		}
				else if (strchr(word, guess[i] != NULL))
				{
					printf("\033[90m%c\033[0m", guess[i]); //yellow
					//edgecases??
				}

				else if (guess[i] == word[i])
				{	
				    printf("\033[92m%c\033[0m", guess[i]); //green
				}

				else if (guess[i] != word[i])
				{
					 printf("\033[90m%c\033[0m", guess[i]); //grey
				}
			}
			attempts++;
		}
	printf("you reached your max attempts, try again!\n");
	}
}

bool    ft_check_yellow(t_data *d, char *input, int i)
{
    int	check;

    if (!strchr(d->word, input[i]))
	{
        return (false);
	}

    check = d->table[((int)d->word[i]) - 'a'];

    for (int j = 0; j < i; j++)
    {
        for (int k = 0; k < i; k++)
        {
            if (input[j] == d->word[k] && check > 0)
            {
                check--;
                break;
            }
        }
    }
    for (int j = i + 1; j < 5; j++)
    {
        if (input[i] == d->word[j] && input[j] == d->word[j] && check > 0)
            check--;
    }
    if (check > 0)
        return (true);
    return (false);
}
/*
{
	table_destroy(&database);
	return (SUCCESS);
}*/
