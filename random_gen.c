#include <time.h>
#include "push_swap.h"

char *randomgen(int a)
{
	char *str;

	str = malloc(2);
	str[0] = ' ';
	str[1] = 0;
	srand(time(NULL));
	while (a)
	{
		str = ft_strjoin(str, " ");
		if (rand() % 2)
			str = ft_strjoin(str, "-");
		str = ft_strjoin(str, ft_itoa(rand()));
		a--;
	}
	return (str);
}