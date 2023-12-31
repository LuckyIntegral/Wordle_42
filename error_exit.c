/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 01:32:51 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/11 01:36:02 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

void	exit_program(char *status)
{
	write(2, status, strlen(status));
	exit(1);
}
