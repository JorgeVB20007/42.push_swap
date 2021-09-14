/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 23:35:38 by jvacaris          #+#    #+#             */
/*   Updated: 2021/09/14 23:35:42 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	slideup(long **list, long size)
{
	long	a;

	a = 1;
	if (size > 1)
	{
		while (a < size && list[0][a] != MT)
		{
			list[0][a - 1] = list[0][a];
			a++;
		}
		list[0][a - 1] = MT;
	}
}

void	slidedwn(long **list, long size)
{
	long	a;

	a = size - 1;
	if (size > 0)
	{
		while (a > 0)
		{
			list[0][a] = list[0][a - 1];
			a--;
		}
		list[0][0] = MT;
	}
}

void	sx(long **list, long size)
{
	long	aux;

	aux = 0;
	if (size >= 2)
	{
		aux = list[0][0];
		list[0][0] = list[0][1];
		list[0][1] = aux;
	}
}

void	px(long **dep, long **arr, long size)
{
	if (arr[0][size - 1] == MT && dep[0][0] != MT)
	{
		slidedwn(arr, size);
		arr[0][0] = dep[0][0];
		slideup(dep, size);
	}
}

void	rx(long **list, long size)
{
	long	aux;
	long	a;

	a = 0;
	if (size >= 2)
	{
		aux = list[0][0];
		slideup(list, size);
		while (list[0][a] != MT && a < size)
			a++;
		list[0][a] = aux;
	}
}

void	rrx(long **list, long size)
{
	long	aux;
	long	a;

	a = 0;
	if (size >= 2)
	{
		while (list[0][a + 1] != MT && a + 1 < size)
			a++;
		aux = list[0][a];
		list[0][a] = MT;
		slidedwn(list, size);
		list[0][0] = aux;
	}
}
