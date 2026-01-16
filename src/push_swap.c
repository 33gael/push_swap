/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:56:22 by gaeducas          #+#    #+#             */
/*   Updated: 2026/01/16 10:14:49 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	int	j;
	int	i;
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
		if (*numbers = validate_input(av[j]) == ERROR)
			free(numbers);
		if (*numbers = parse_int(av[j], numbers) == ERROR)
			free(numbers);
		if (*numbers = check_duplicates(&numbers, count) == ERROR)
			free(numbers);
		j++;
	}
	return (0);
}
