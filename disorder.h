#ifndef DISORDER_H
#define DISORDER_H

//stack
typedef struct stack
{
	int	*val;
	struct stack *next;
}	stack;

//bench struct
typedef struct bench
{
	double	*disorder;
	char	*strategy;
	int		*total_op;
	int		*sa_count;
	int		*sb_count;
	int		*ss_count;
	int		*pa_count;
	int		*pb_count;
	int		*ra_count;
	int		*rb_count;
	int		*rr_count;
	int		*rra_count;
	int		*rrb_count;
	int		*rrr_count;
}	bench;

//libft
#include "libft/libft.h"

#endif
