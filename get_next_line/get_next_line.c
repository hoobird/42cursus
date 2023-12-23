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
	static char	*memline;
	char		*nextline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	memline = readnextline(fd, memline);
	if (memline)
	{
		nextline = splitline(memline);
		memline = shiftline(memline);
		return (nextline);
	}
	return (NULL);
}

char	*readnextline(int fd, char *memline)
{
	char	*buf;
	int		readsize;

	// if (memline == NULL)
	// 	memline = malloc(0);
	readsize = 1;
	while (newlinefound(memline) == 0 && readsize)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return (NULL);
		readsize = read(fd, buf, BUFFER_SIZE);
		if (readsize < 0)
			return (myfree(&buf), myfree(&memline), NULL);
		buf[readsize] = '\0';
		memline = ft_strjoin(memline, buf);
	}
	return (memline);
}

char   *splitline(char *memline)
{
	int		i;
	char	*temp;

	i = 0;
	temp = malloc(sizeof(char) * (ft_strlen(memline) + 1));
	if (!temp || !memline[0])
		return (myfree(&temp), NULL);
	while (memline[i] != '\0')
	{
		temp[i] = memline[i];
		i++;
		if (memline[i] == '\n')
			break ;	
	}
	temp[i] = '\0';
	return (temp);
}

char	*shiftline(char *memline)
{
	int		newlen;
	char	*newline;
	char	*temp;

	newline = ft_strchr(memline, '\n');
	temp = NULL;
	if (newline)
	{
		newlen = ft_strlen(newline + 1);
		temp = malloc(sizeof(char) * (newlen + 1));
		if (!temp)
			return (myfree(&temp), NULL);
		ft_strlcpy(temp, newline + 1, newlen + 1);	
	}
	myfree(&memline);
	return (temp);
}