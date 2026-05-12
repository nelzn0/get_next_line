/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:21:58 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/12 16:01:57 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*result;

	fd = open(argv[1], O_RDONLY);

	result = get_next_line(fd);

	while (result)
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
