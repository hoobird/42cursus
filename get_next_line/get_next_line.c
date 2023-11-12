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

void	currlinetolist(t_list *list, int fd)
{
	char *temp;
	int		count;
	t_list *templist;

	while (hasnewline(list) == 0)
	{
		temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!temp)
			return;
		count = read(fd, &temp, BUFFER_SIZE);
		if (count == 0)
		{
			free(temp);
			return;
		}
		temp[count] = 0;
		templist = ft_lstnew(temp);
		if (!templist)
			return;
		ft_lstadd_back(list, templist);
	}
}

char *linetostr(t_list *list)
{
	char *output;

	output = malloc(getoutputlen(list) + 1);
	if (output == NULL)
		return (NULL);
	listtostr(list, output);
	return (output);
}

int getoutputlen(t_list *list)
{
	int len;
	int i;

	len = 0;
	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
				return (++len);
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);

}

void resetlist(t_list *list)
{
	t_list	*last;
	t_list	*resetted;
	char*	temp;
	int		i;
	int		j;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return;
	last = ft_lstlast(list);
	i = 0;
	while (last->content[i] != '\n' || last->content[i] != 0)
		i++;
	j = 0;
	while (last->content[i] != 0 && last->content[++i])
		temp[j++] = last->content[i];
	temp[j] = 0;
	resetted = ft_lstnew(temp);
	if (!resetted)
		return ;
	ft_lstclear(&list, free);
	list = resetted;		
}

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