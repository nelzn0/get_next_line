/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 20:25:37 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/07 14:29:38 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *stash)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*old_stash;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		old_stash = stash;
		stash = ft_strjoin(old_stash, buf);
		if (!stash)
			return (NULL);
		free(old_stash);
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	return (stash);
}

char	*ft_trim_stash(char *stash)
{
	char	*trim_stash;

	if (!stash)
		return (NULL);
	if (!ft_strchr(stash, '\n'))
		return (NULL);
	trim_stash = ft_substr(stash, ft_strchr(stash, '\n') - stash + 1, ft_strlen(stash));
	return (trim_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*first_line;
	char		*old_stash;

	stash = ft_read_file(fd, stash);
	if (!stash)
		return (NULL);
	first_line = ft_first_line(stash);
	old_stash = stash;
	stash = ft_trim_stash(old_stash);
	free(old_stash);
	return (first_line);
}
