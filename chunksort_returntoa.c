/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunksort_returntoa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 20:32:19 by jvacaris          #+#    #+#             */
/*   Updated: 2021/09/15 20:32:22 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_towers	returntoathird(t_towers tower, long dir)
{
	if (dir == -1)
		rx(&(tower.b), tower.size);
	else
		rrx(&(tower.b), tower.size);
	if (dir == -1)
		addlog(&tower.log, "rb");
	else
		addlog(&tower.log, "Rb");
	return (tower);
}

static t_towers	returntoasecond(t_towers tower, long *min, long *max, long b)
{
	long	a;
	long	dir;

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
		tower = returntoathird(tower, dir);
	}
	return (tower);
}

t_towers	returntoa(t_towers	tower, long *min, long *max)
{
	long	b;

	b = 0;
	while (tower.b[b] != MT)
		b++;
	b--;
	while (tower.b[0] != MT)
	{
		tower = returntoasecond(tower, min, max, b);
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
