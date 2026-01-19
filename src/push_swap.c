/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:56:22 by gaeducas          #+#    #+#             */
/*   Updated: 2026/01/19 15:22:10 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	validate_and_parse_array(char **av, int *numbers, int count)
{
	int	j;

	j = 1;
	while (j < count + 1)
	{
		if (validate_input(av[j]) == ERROR)
			return (ERROR);
		if (parse_int(av[j], &numbers[j - 1]) == ERROR)
			return (ERROR);
		j++;
	}
	if (check_duplicates(numbers, count) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

static int	*parse_arguments(int ac, char **av, int *count)
{
	int	*numbers;

	*count = ac - 1;
	numbers = malloc(sizeof(int) * (*count));
	if (!numbers)
		return (NULL);
	if (validate_and_parse_array(av, numbers, *count) == ERROR)
	{
		free(numbers);
		return (NULL);
	}
	return (numbers);
}

static t_node	*handle_stack_creation(int *numbers, int count)
{
	t_node	*stack;

	stack = init_stack(numbers, count);
	free(numbers);
	if (!stack)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	return (stack);
}

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

int	main(int ac, char **av)
{
	int		count;
	int		*numbers;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_b = NULL;
	if (ac < 2)
		return (1);
	numbers = parse_arguments(ac, av, &count);
	if (!numbers)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stack_a = handle_stack_creation(numbers, count);
	if (!stack_a)
		return (1);
	if (!is_sorted(stack_a))
		sort_stack(&stack_a, &stack_b, stack_size(stack_a));
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
