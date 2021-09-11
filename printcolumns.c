#include "push_swap.h"

void	printcolumns(t_towers tower)
{
	int	a;

	a = 0;
	printf("\n\n ––––––––––––––– –––––––––––––––     –––––––––––––––\n|   COLUMN  A   |   COLUMN  B   |   | CORRECT ORDER |\n|–––––––––––––––+–––––––––––––––|   |–––––––––––––––|\n");
	while (a < tower.size)
	{
		printf("| [%11ld] | [%11ld] |   | [%11ld] |\n", tower.a[a], tower.b[a], tower.corr[a]);
		a++;
	}
	printf("|–––––––––––––––|–––––––––––––––|   |–––––––––––––––|\n");
	printf("| %8ld      | %8ld      |   | %8ld      |\n", tower.soa, tower.sob, tower.size);
	printf(" ––––––––––––––– –––––––––––––––     –––––––––––––––\n");
/*	if (checkorder(tower))
		printf("      THE LIST IS SORTED!\n");
	else
		printf("     THE LIST'S NOT SORTED\n");*/
}