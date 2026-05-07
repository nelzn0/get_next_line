/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:21:58 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/07 13:37:46 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int fd;
	char *file;
	char *result;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	result = get_next_line(fd);
	while (result != NULL)
	{
		printf("%s \n", result);
		free (result);
		result = get_next_line(fd);
	}
	close (fd);
}
