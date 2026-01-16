/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:56:22 by gaeducas          #+#    #+#             */
/*   Updated: 2026/01/16 10:59:21 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_error(int *numbers)
{
	ft_putstr_fd("Error\n", 2);
	free(numbers);
	return (1);
}

int	main(int ac, char **av)
{
	int	j;
	int	count;
	int	*numbers;

	if (ac < 2)
		return (1);
	count = ac - 1;
	numbers = malloc(sizeof(int) * count);
	if (!numbers)
		return (1);
	j = 1;
	while (j < ac)
	{
		if (validate_input(av[j]) == ERROR)
			return (ft_error(numbers));
		if (parse_int(av[j], &numbers[j - 1]) == ERROR)
			return (ft_error(numbers));
		j++;
	}
	if (check_duplicates(numbers, count) == ERROR)
		return (ft_error(numbers));
	return (0);
}
