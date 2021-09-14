/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 23:37:07 by jvacaris          #+#    #+#             */
/*   Updated: 2021/09/14 23:37:09 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	errmsg(char a)
{
	a = 0;
	write(1, "Error ", 6);
	write(1, "\n", 1);
	exit(0);
}

void	freestuff(t_towers *tower)
{
	free((*tower).a);
	free((*tower).b);
	free((*tower).corr);
	free((*tower).log);
}

int	main(int argc, char **argv)
{
	t_towers	tower;

	tower = organizestruct(argc, argv);
	if (checkorder(tower.a, tower.size))
		return (0);
	docorrectorder(tower.a, &tower.corr, tower.size);
	if (tower.size == 2)
		tower.log = twonums(tower.a);
	else if (tower.size == 3)
		tower.log = threenums(tower.a);
	else if (tower.size == 5)
		tower = fivenums(tower);
	else if (tower.size > 100 && tower.size <= 500)
		tower.div = 90;
	else if (tower.size > 50 && tower.size <= 100)
		tower.div = 40;
	else
		tower = bubblesort(tower);
	if (tower.div != 0)
		tower = chunksort(tower);
	improvelog(&tower.log);
	printlog(tower.log);
	return (0);
}
