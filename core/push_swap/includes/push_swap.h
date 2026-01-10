#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

/* ************************************************************************** */
/*                                  STRUCTS                                   */
/* ************************************************************************** */

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* ************************************************************************** */
/*                              STACK UTILITIES                               */
/* ************************************************************************** */

t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new_stack);
void	stack_add_front(t_stack **stack, t_stack *new_stack);
int		stack_size(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
void	free_stack(t_stack **stack);

/* ************************************************************************** */
/*                              PARSING / INIT                                */
/* ************************************************************************** */

void	parse_args(int argc, char **argv, t_stack **a);
void	check_duplicates(t_stack *a);
void	assign_index(t_stack *a);
int		is_sorted(t_stack *a);

/* ************************************************************************** */
/*                               OPERATIONS                                   */
/* ************************************************************************** */

/* swap */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

/* push */
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

/* rotate */
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

/* reverse rotate */
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* ************************************************************************** */
/*                                SORTING                                     */
/* ************************************************************************** */

void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
void	radix_sort(t_stack **a, t_stack **b);

/* ************************************************************************** */
/*                                  ERROR                                     */
/* ************************************************************************** */

void	error_exit(void);

#endif
