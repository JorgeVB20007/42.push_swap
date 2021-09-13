#include "push_swap.h"

void	errmsg(char a)
{
	a = 0;
	write(1, "Error ", 6);
//	write(1, &a, 1);
	write(1, "\n", 1);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_towers	tower;
	char		**ran;
	long		count = 200;
	long		attempts = 250;
	int			wait = 100;

	if (argv)
		printf("\n");
	ran = malloc(2);
	ran[0] = malloc(2);
	ran[0][0] = 'a';
	ran[0][1] = 0;
	while (count > 2)
	{
		write(1, "\n", 1);
//		ft_putnbr_fd(count, 0);
//		write(1, ": ", 2);
		attempts = 250;
		wait = 2000000;
		while (wait--)
			write(1, ".", 0);
		ran[1] = randomgen(500);
		while (attempts > 15)
		{
			tower = organizestruct(argc, ran);
			tower.div = attempts;
			docorrectorder(tower.a, &tower.corr, tower.size);
			tower = chunksort(tower);
			improvelog(&tower.log);
			ft_putnbr_fd(countlog(tower.log), 0);
			write(1, "\t", 1);
			free(tower.a);
			free(tower.b);
			free(tower.corr);
			free(tower.log);
			attempts -= 5;
		}
		count -= 1;
	}
/*
	ran[1] = randomgen(100);

	tower = organizestruct(argc, argv);
	if (checkorder(tower.a, tower.size))
		return (0);
	docorrectorder(tower.a, &tower.corr, tower.size);
	tower = chunksort(tower);
	improvelog(&tower.log);
	printlog(tower.log);

//	manualcontrol(&tower);*/
	return (0);
}
