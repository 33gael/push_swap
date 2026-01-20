/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 22:25:44 by gaeducas          #+#    #+#             */
/*   Updated: 2026/01/20 10:03:59 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_max_pos(t_node *stack, int max_index)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == max_index)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

static void	push_back_to_a(t_node **a, t_node **b)
{
	int	size;
	int	max_pos;

	while (*b)
	{
		size = stack_size(*b);
		max_pos = find_max_pos(*b, size - 1);
		if (max_pos <= size / 2)
		{
			while ((*b)->index != size - 1)
				rb(b);
		}
		else
		{
			while ((*b)->index != size - 1)
				rrb(b);
		}
		pa(a, b);
	}
}

static int	get_n(int size)
{
	if (size <= 100)
		return (15);
	return (30);
}

void	butterfly_sort(t_node **a, t_node **b)
{
	int	n;
	int	counter;
	int	size;

	size = stack_size(*a);
	n = get_n(size);
	counter = 0;
	index_stack(a);
	while (*a)
	{
		if ((*a)->index <= counter)
		{
			pb(a, b);
			rb(b);
			counter++;
		}
		else if ((*a)->index <= counter + n)
		{
			pb(a, b);
			counter++;
		}
		else
			ra(a);
	}
	push_back_to_a(a, b);
}
