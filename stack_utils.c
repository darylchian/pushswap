/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchian <tchian@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 19:41:57 by tchian            #+#    #+#             */
/*   Updated: 2026/11/07 21:02:52 by tchian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack *node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);

	node->value = value;
	node->index = -1;

	node->next = NULL;
	node->prev = NULL;

	return (node);
}

void	add_note_bottom(t_stack **stack, t_stack *new_n)
{
	t_stack *last;

	if (!stack || !new_n)
		return;
	if (!*stack)
	{
		*stack = new_n;
		return;
	}
	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new_n;
	new_n->prev = last;
}

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		size++;
		stack = stack ->next;
	}
	return (size);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack || !*stack)
		return;
	current = *stack;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

//By setting the index to -1 right when a node is born, .
//you are planting a flag that says: "This box contains a raw, unranked number.
//The brain of the program has not scanned the other boxes yet to calculate its final rank position."
//1. create a new node box
//2. ADD A NODE TO THE VERY BOTTOM
//3. Count the stack size
//4. Destroy the stack/free memory
