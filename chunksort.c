#include "push_swap.h"

int	numsinrange(long *list, long sol, long max, long min)
{
	long	a;

	a = 0;
	while (a < sol)
	{
		if (list[a] >= min && list[a] <= max)
			return (1);
		a++;
	}
	return (0);
}

t_towers	returntoa(t_towers	tower, long *min, long *max)
{
	long	a;
	long	b;
	int		dir;

	b = 0;
	while (tower.b[b] != MT)
		b++;
	b--;
	while (tower.b[0] != MT)
	{
		a = -1;
		dir = 0;
		while (!dir)
		{
			a++;
			if (tower.b[a] == *min || tower.b[a] == *max)
				dir = -1;
			else if (tower.b[b - a] == *min || tower.b[b - a] == *max)
			{
				a++;
				dir = 1;
			}
		}
		while (a-- > 0)
		{
			if (dir == -1)
				rx(&(tower.b), tower.size);
			else
				rrx(&(tower.b), tower.size);
			if (dir == -1)
				addlog(&tower.log, "rb");
			else
				addlog(&tower.log, "Rb");
		}
		px(&(tower.b), &(tower.a), tower.size);
		addlog(&tower.log, "pa");
		if (tower.a[0] == *max)
			max--;
		else
		{
			rx(&(tower.a), tower.size);
			addlog(&tower.log, "ra");
			min++;
		}
		b--;
	}
	return (tower);
}

t_towers	movetob(t_towers tower, long min, long max)
{
	while (numsinrange(tower.a, tower.size, max, min))
	{
		if (tower.a[0] >= min && tower.a[0] <= max)
		{
			px(&tower.a, &tower.b, tower.size);
			addlog(&tower.log, "pb");
		}
		else
		{
			rx(&tower.a, tower.size);
			addlog(&tower.log, "ra");
		}	
	}
	return (tower);
}

t_towers	chunksort(t_towers tower)
{
	long	amogr;
	long	round;
	long	*max;
	long	*min;

	amogr = (tower.size / (long)tower.div) + !!(tower.size % (long)tower.div);
	round = amogr;
	while (round > 0)
	{
		if (round == amogr)
			max = &tower.corr[tower.size - 1];
		else
			max = &tower.corr[(tower.size / amogr) * round];
		min = &tower.corr[(tower.size / amogr) * (--round)];
		tower = movetob(tower, *min, *max);
		tower = returntoa(tower, min, max);
	}
	while (tower.a[round] != tower.corr[0])
	{
		rrx(&(tower.a), tower.size);
		addlog(&tower.log, "Ra");
	}
	return (tower);
}
