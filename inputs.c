#include "push_swap.h"

long	countandcheckbs(char *str, long n)
{
	long		a;

	a = 0;
	while (str[a])
	{
		while (str[a] == ' ')
			a++;
		if (str[a] == '-' || str[a] == '+')
			a++;
		if (ft_isdigit(str[a]))
		{
			while (ft_isdigit(str[a]))
				a++;
			n++;
			if (str[a] != ' ' && str[a])
				errmsg('a');
		}
		else if (str[a])
			errmsg('b');
		while (str[a] == ' ' && str[a])
			a++;
	}
	return (n);
}

t_towers	reservememory(long n)
{
	long		a;
	t_towers	tower;

	a = 0;
	tower.size = n;
	tower.soa = n;
	tower.sob = 0;
	tower.a = malloc(sizeof(long) * n);
	tower.b = malloc(sizeof(long) * n);
	tower.corr = malloc(sizeof(long) * n);
	if (!tower.a || !tower.b || !tower.corr)
		exit(0);
	while (a < n)
	{
		tower.a[a] = MT;
		tower.b[a] = MT;
		tower.corr[a] = MT;
		a++;
	}
	return (tower);
}

t_towers	chartolong(t_towers tower, char *str)
{
	long	n;
	long	index;
	int		a;
	int		neg;

	index = 0;
	a = 0;
	while (str[a])
	{
		n = 0;
		neg = 0;
		while ((str[a] == ' ' || str[a] == '+' || str[a] == '-') && str[a])
			a++;
		if (str[a - 1] == '-')
			neg = 1;
		while (ft_isdigit(str[a]))
		{
			n = n * 10 + str[a] - '0';
			if (n > (long)2147483647 + (long)neg)
				errmsg('c');
			a++;
		}
		tower.a[index++] = n * ((neg * -2) + 1);
	}
	return (tower);
}

void	checkfordupes(long *list, long size)
{
	long	a;
	long	b;

	a = 0;
	b = 1;
	while (a < size)
	{
		b = a + 1;
		while (b < size)
		{
			if (list[a] == list[b])
				errmsg('d');
			b++;
		}
		a++;
	}
}

t_towers	organizestruct(int agc, char **agv)
{
	char		*str;
	t_towers	tower;
	long		len;

	len = 0;
	if (agc < 2)
		errmsg('g');
	str = joinparams(agc, agv);
	len = countandcheckbs(str, 0);
	if (!len)
		errmsg('h');
	tower = reservememory(len);
	tower = chartolong(tower, str);
	checkfordupes(tower.a, tower.size);
	return (tower);
}
