#include "libft.h"

int	ccount(char const *s, char c)
{
	char	ss;
	int		cnt;
	
	cnt = 0;
	ss = (char *) s;
	while (*ss)
	{
		if (*ss == c)
			cnt++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	int		size;
	int		c;
	
	size = ccount(s, c) + 1;
	output = (char **) malloc(sizeof(char *) * size);
	c = 0;
	while (c < size - 1)
	{
		

	}

}
