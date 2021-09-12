#include <time.h>
#include "push_swap.h"

char *randomgen(void)
{
	char *str;
	int a = 99;

	str = malloc(2);
	str[0] = ' ';
	str[1] = 0;
	srand(time(NULL));
	while (a)
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, ft_itoa(rand()));
		a--;
	}
	return (str);
}