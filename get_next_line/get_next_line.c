/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoobird <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:03:11 by hoobird           #+#    #+#             */
/*   Updated: 2023/09/26 21:04:26 by hoobird          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*memline = NULL;
	char		*nextline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readnextline(fd, memline);
	if (memline == NULL)
		return (NULL);
	nextline = ft_strchr(memline, '\n');
	return (nextline);
}

void readnextline(int fd, char *memline)
{
	char	*buf;
	int		readsize;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (newlinefound(memline) == 0 && readsize)
	{
		readsize = read(fd, buf, BUFFER_SIZE);
		if (readsize < 0)
			return (myfree(&buf), myfree(&memline),NULL);
		buf[readsize] = '\0';
		memline = ft_strjoin(memline, buf);
	}
	myfree(&buf);
	return (memline);
}

