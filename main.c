/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:21:58 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/08 15:52:06 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*result;
	char	*error;

	fd = open("only_nl.txt", O_RDONLY);

	result = get_next_line(fd);

	while (result != NULL)
	{
		printf("%s \n", result);
		free (result);
		result = get_next_line(fd);
	}
	close (fd);

	error = get_next_line(-1);
	if (!error)
		printf("INVALID FILE DESCRIPTOR!\n");

	return (0);
}
