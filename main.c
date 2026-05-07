/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:21:58 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/07 14:41:36 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*result;

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
	printf("%s\n", get_next_line(-1));
	close (fd);
}
