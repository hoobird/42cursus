#include "libft.h"

int	countdigits(int n)
{
	int	count;
	
	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char *ft_itoa(int n)
{
	int		size;
	char	*output;
	int		ind;
	
	size = countdigits(n);
	output = malloc(size + 1);
	ind = 0;
	if (n < 0)
	{
		output[ind++] = '-';
		n = -n;
	}
	while (size > ind)
	{
		output[--size] = '0' + (n % 10);
		n /= 10;	
	}
	return (output);
}
