#include "push_swap.h"

void	manualcontrol(t_towers *tower)
{
	char	*line;

	printf("\n  ~~~~~~~~~~ MANUAL CONTROL IS ON ~~~~~~~~~~\n");
	while (1)
	{
		get_next_line(0, &line);
		if (line[0] == 's' && line[1] == 'a')
			sx(&(tower->a), tower->size);
		if (line[0] == 's' && line[1] == 'b')
			sx(&(tower->b), tower->size);
		if (line[0] == 's' && line[1] == 's')
		{
			sx(&(tower->a), tower->size);
			sx(&(tower->b), tower->size);
		}
		if (line[0] == 'p' && line[1] == 'a')
			px(&(tower->b), &(tower->a), tower->size);
		if (line[0] == 'p' && line[1] == 'b')
			px(&(tower->a), &(tower->b), tower->size);
		if (line[0] == 'r' && line[1] == 'a')
			rx(&(tower->a), tower->size);
		if (line[0] == 'r' && line[1] == 'b')
			rx(&(tower->b), tower->size);
		if (line[0] == 'r' && line[1] == 'r')
		{
			rx(&(tower->a), tower->size);
			rx(&(tower->b), tower->size);
		}
		if (line[0] == 'R' && line[1] == 'a')
			rrx(&(tower->a), tower->size);
		if (line[0] == 'R' && line[1] == 'b')
			rrx(&(tower->b), tower->size);
		if (line[0] == 'R' && line[1] == 'r')
		{
			rrx(&(tower->a), tower->size);
			rrx(&(tower->b), tower->size);
		}
		if (line[0] == 'e')
			break ;
		printcolumns(*tower);
	}

}