#include "libft.h"

int	ccount(char const *s, char c)
{
	char	*ss;
	int		cnt;
	
	cnt = 0;
	ss = (char *) s;
	while (*ss)
	{
		if (*ss == c)
			cnt++;
		ss++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	int		space;
	char	*frt;
	char	*bck;
	char	*temp;
	
	space = 0;
	output = (char **) malloc(sizeof(char *) * ccount(s, c) + 1);
	frt = (char *) s;
	bck = frt;
	while (*bck)
	{
		if (*bck == c)
		{
			temp = malloc(bck - frt + 1);
			ft_strlcpy(temp, frt, bck - frt + 1);
			output[space++] = temp;
			frt = bck + 1;
		}
		bck++;
	}
	temp = malloc(bck - frt + 1);
	ft_strlcpy(temp, frt, bck - frt + 1);
	output[space] = temp;
	return (output);
}
