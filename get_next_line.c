/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 20:25:37 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/08 13:24:40 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *stash)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*old_stash;

	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(stash), NULL);
		if (bytes_read == 0)
			return (stash);
		buf[bytes_read] = '\0';
		old_stash = stash;
		stash = ft_strjoin(old_stash, buf);
		free(old_stash);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

char	*ft_trim_stash(char *stash)
{
	char	*trim_stash;
	char	*new_line;

	if (!stash)
		return (NULL);
	new_line = ft_strchr(stash, '\n');
	if (!new_line || *(new_line + 1) == '\0')
		return (NULL);
	trim_stash = ft_substr(stash, (new_line - stash) + 1,
			ft_strlen(new_line + 1));
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
	if (*stash == '\0')
		return (free(stash), stash = NULL, NULL);
	first_line = ft_first_line(stash);
	if (!first_line)
		return (free(stash), stash = NULL, NULL);
	old_stash = stash;
	stash = ft_trim_stash(old_stash);
	free(old_stash);
	return (first_line);
}
