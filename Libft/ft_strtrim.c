#include "libft.h"

int	isset(char c, char const *set)
{
	int	counter;

	counter = 0;
	while (set[counter])
	{
		if (c == set[counter])
			return (1);
		counter++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		counter;
	int		length;
	char	*s2;
	char	*retval;

	counter = 0;
	length = ft_strlen(s1);
	s2 = (char *) s1;
	while (*s2)
	{
		if (isset(*s2, set))
			length--;
		s2++;
	}
	retval = malloc(sizeof(char) * (length + 1));
	s2 = (char *) s1;
	while (*s2)
	{
		if (!(isset(*s2, set)))
			*retval++ = *s2;
		s2++;
	}
	*retval = '\0';
	return (retval - length);
}
