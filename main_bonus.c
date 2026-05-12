/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 15:41:14 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/12 16:01:12 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*result;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);

	result = get_next_line(fd1);
	printf("File 1, Line 1: %s", result);
	free(result);

	result = get_next_line(fd2);
	printf("File 2, Line 1: %s", result);
	free(result);

	result = get_next_line(fd1);
	printf("File 1, Line 2: %s", result);
	free(result);

	result = get_next_line(fd2);
	printf("File 2, Line 2: %s", result);
	free(result);

	close(fd1);
	close(fd2);
	return (0);
}
