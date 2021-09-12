#include "push_swap.h"

void	errmsg(char a)
{
	write(1, "Error ", 6);
	write(1, &a, 1);
	write(1, "\n", 1);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_towers	tower;

	*argv = randomgen();
	tower = organizestruct(argc, argv);
	if (checkorder(tower.a, tower.size))
		return (0);
	docorrectorder(tower.a, &tower.corr, tower.size);
	printcolumns(tower);
	tower = chunksort(tower);
	printcolumns(tower);
//	manualcontrol(&tower);
	return (0);
}
