#include "fdf.h"

void	error(const char *str)
{
	perror(str);
	write(2, "\n", 1);
	exit(1);
}

void	merror(void *ptr)
{
	if (ptr == 0)
	{
		write(2, "Malloc error\n", 14);
		exit(2);
	}
}

int		find_max(int a, int b, int c)
{
	if (a >= b)
	{
		if (a >= c)
			return (a);
	}
	else
	{
		if (b >= c)
			return (b);
	}
	return (c);
}
