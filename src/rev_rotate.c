/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:02:51 by gaeducas          #+#    #+#             */
/*   Updated: 2026/01/20 14:36:44 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rev_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*prev;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_node **stack_a)
{
	rev_rotate(stack_a);
	ft_printf("%s", "rra\n");
}

void	rrb(t_node **stack_b)
{
	rev_rotate(stack_b);
	ft_printf("%s", "rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_printf("%s", "rrr\n");
}
