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
	static t_list	*list = NULL;
	char			*nextline;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &nextline, 0) < 0)
		return (NULL);
	currlinetolist(&list, fd);
	if (list == NULL)
		return (NULL);
	nextline = linetostr(list);
	resetlist(list);
	return (nextline);
}

void	currlinetolist(t_list *list, int fd)
{
	char	*temp;
	int	count;
	t_list	*templist;

	while (hasnewline(list) == 0)
	{
		temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!temp)
			return ;
		count = read(fd, &temp, BUFFER_SIZE);
		if (count == 0)
		{
			free(temp);
			return ;
		}
		temp[count] = 0;
		templist = ft_lstnew(temp);
		if (!templist)
			return ;
		ft_lstadd_back(templist);
	}
}

int	hasnewline(t_list *list)
{
	char	*str;
	
	str = list->content;
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char 	*linetostr(t_list *list)
{
	char	*output;

	
}

void	resetlist()
{

}
