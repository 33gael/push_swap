/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:43:29 by gaeducas          #+#    #+#             */
/*   Updated: 2026/01/19 15:23:05 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	stack_add_back(t_node **stack, t_node *new_node)
{
	t_node	*current;

	if (!new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

t_node	*init_stack(int *numbers, int count)
{
	t_node	*stack;
	t_node	*new_node;
	int		i;

	stack = NULL;
	i = 0;
	while (i < count)
	{
		new_node = create_node(numbers[i]);
		if (!new_node)
		{
			free_stack(&stack);
			return (NULL);
		}
		stack_add_back(&stack, new_node);
		i++;
	}
	return (stack);
}
