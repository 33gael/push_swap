/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 10:16:08 by gaeducas          #+#    #+#             */
/*   Updated: 2026/01/20 14:36:46 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_node *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	sa(t_node **stack_a)
{
	swap(*stack_a);
	ft_printf("%s", "sa\n");
}

void	sb(t_node **stack_b)
{
	swap(*stack_b);
	ft_printf("%s", "sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_printf("%s", "ss\n");
}
