/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:50:45 by marvin            #+#    #+#             */
/*   Updated: 2026/01/09 00:23:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

// buffersize for gnl
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// headers
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

// structs
typedef struct t_stack
{
	int				value;
    int             index;
	struct t_stack	*next;
}					t_stack;

typedef struct s_data
{
	t_stack			*a;
	t_stack			*b;
}					t_data;

// operations
void				sa(t_data *data);
void				sb(t_data *data);
void				ss(t_data *data);
void				pa(t_data *data);
void				pb(t_data *data);

void				ra(t_data *data);
void				rb(t_data *data);
void				rr(t_data *data);

void				rra(t_data *data);
void				rrb(t_data *data);
void				rrr(t_data *data);

// parsing
int					duplicate(t_stack *stack, int num);
t_stack				*store(int content);
void				add_stack(t_stack **numbers, t_stack *store);
int					parsing_arg(char *stack, t_stack **digit_stack);

// checker
void				checker(t_data *data);

// get next line
char				*gnl_strjoin(char *s1, char *s2);
char				*gnl_strchr(const char *s, int c);
char				*gnl_buffer(char *buf);
char				*alloc_newbuffer(size_t i, size_t alloc, char *buf);
char				*get_next_line(int fd);
char				*gnl_substr(char *buf);
size_t				gnl_strlen(const char *s);

// utils
void				free_stack(t_data *data);
int					is_sorted(t_data *data);
void				init_data(t_data *data);

#endif