/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 22:20:38 by gaeducas          #+#    #+#             */
/*   Updated: 2026/01/19 09:56:58 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_min_pos(t_node *stack)
{
	int	min;
	int	min_pos;
	int	i;

	min = stack->value;
	min_pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_pos);
}

void	sort_three(t_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_five(t_node **a, t_node **b)
{
	int	min_pos;
	int	size;

	size = stack_size(*a);
	while (size > 3)
	{
		min_pos = find_min_pos(*a);
		if (min_pos == 0)
			pb(a, b);
		else if (min_pos <= size / 2)
			ra(a);
		else
			rra(a);
		if (stack_size(*a) < size)
			size--;
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}
