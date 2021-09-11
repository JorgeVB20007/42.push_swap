#include "push_swap.h"

void	errmsg(char a)
{
	write(1, "Error ", 6);
	write(1, &a, 1);
	write(1, "\n", 1);
	exit(0);
}

int main(int argc, char **argv)
{
	t_towers	tower;

	tower = organizestruct(argc, argv);
	printcolumns(tower);
	return (0);
}