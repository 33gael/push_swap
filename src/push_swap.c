/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:56:22 by gaeducas          #+#    #+#             */
/*   Updated: 2026/01/20 14:36:42 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_stack(t_node **a, t_node **b, int size)
{
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		butterfly_sort(a, b);
}

static void	free_resources(t_node **a, t_node **b, int *n)
{
	free_stack(a);
	free_stack(b);
	if (n)
		free(n);
	ft_putstr_fd("Error\n", 2);
}

static int	*parse_args_wrapper(int ac, char **av, int *count)
{
	int	*numbers;

	*count = count_args(ac, av);
	if (*count == ERROR || *count == 0)
		return (NULL);
	numbers = malloc(sizeof(int) * (*count));
	if (!numbers)
		return (NULL);
	if (get_numbers(ac, av, numbers) == ERROR)
	{
		free(numbers);
		return (NULL);
	}
	if (check_duplicates(numbers, *count) == ERROR)
	{
		free(numbers);
		return (NULL);
	}
	return (numbers);
}

int	main(int ac, char **av)
{
	int		count;
	int		*numbers;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_b = NULL;
	if (ac < 2)
		return (0);
	numbers = parse_args_wrapper(ac, av, &count);
	if (!numbers)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stack_a = init_stack(numbers, count);
	free(numbers);
	if (!stack_a)
	{
		free_resources(NULL, NULL, NULL);
		return (1);
	}
	if (!is_sorted(stack_a))
		sort_stack(&stack_a, &stack_b, stack_size(stack_a));
	free_stack(&stack_a);
	free_stack(&stack_b);
}
