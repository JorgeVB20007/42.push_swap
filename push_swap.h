#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <string.h>

# define MT	99999999999
# define DIV 30

typedef struct s_towers
{
	long	*a;
	long	*b;
	long	*corr;
	long	size;
	long	soa;
	long	sob;
}					t_towers;

int			main(int argc, char **argv);
void		errmsg(char a);
char		*joinparams(int agc, char **agv);
t_towers	organizestruct(int agc, char **agv);
void		docorrectorder(long *a, long **corr, long size);
int			checkorder(long *a, long size);
void		sx(long **list, long size);
void		px(long **dep, long **arr, long size);
void		rx(long **list, long size);
void		rrx(long **list, long size);
void		printcolumns(t_towers tower);		// Delete before evaluation
void		manualcontrol(t_towers *tower);

#endif
