/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_slide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 23:50:12 by jvacaris          #+#    #+#             */
/*   Updated: 2021/09/14 23:50:13 by jvacaris         ###   ########.fr       */
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
