/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logmanagement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 23:36:42 by jvacaris          #+#    #+#             */
/*   Updated: 2021/09/14 23:36:44 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addlog(char **log, char *a)
{
	if (!*log)
		*log = ft_calloc(1, 1);
	*log = ft_strjoin(*log, a);
}

void	printlog(char *log)
{
	long	a;

	a = 0;
	while (log[a])
	{
		while (log[a] == ' ')
			a++;
		if (log[a] == 'R')
			write(1, "rr", 2);
		else
			write(1, &log[a], 1);
		a++;
		if (log[a] == 'R')
			write(1, "r", 2);
		else
			write(1, &log[a], 1);
		write(1, "\n", 1);
		a++;
	}
}

void	improvelog(char **log)
{
	long	a;
	long	b;

	a = 0;
	b = a + 2;
	while ((*log)[a])
	{
		if ((*log)[a] == 'p' || (*log)[a + 1] == 's' || (*log)[a + 1] == 'r')
			a = a + 2;
		else
		{
			b = a + 2;
			while ((*log)[b])
			{
				if ((*log)[b] == 'p' || (*log)[b + 1] == 's' || (*log)[b + 1] == 'r')
					break ;
				else if ((*log)[b + 1] == (*log)[a + 1])
					b += 2;
				else if ((*log)[b] != (*log)[a])
					break ;
				else
				{
					(*log)[a + 1] = (*log)[a];
					(*log)[b] = ' ';
					(*log)[b + 1] = ' ';
				}
			}
		}
		a += 2;
	}
}

int	countlog(char *log)
{
	long	a;
	long	res;

	a = 0;
	res = 0;
	while (log[a])
	{
		while (log[a] == ' ')
			a++;
		a += 2;
		res++;
	}
	return (res);
}
