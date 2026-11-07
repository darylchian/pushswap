/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchian <tchian@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 19:41:57 by tchian            #+#    #+#             */
/*   Updated: 2026/11/07 21:12:46 by tchian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* --- Stack Management Utilities (stack_utils.c) --- */

to be amended depending on final description
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b)
void	pa(t_stack **a, t_stack **b)
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* --- Project Logic Tools (algorithm_utils.c) --- */

#endif

//3. struct s_stack *next: The forward pointer. If this node is at the very bottom of your stack, this pointer will be NULL.
// 4. struct s_stack *prev: The backward pointer. If this node is at the very top of your stack, this pointer will be NULL.
