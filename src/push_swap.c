/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:56:22 by gaeducas          #+#    #+#             */
/*   Updated: 2026/01/15 15:49:48 by gaeducas         ###   ########.fr       */
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
	count = j;
	numbers = malloc(sizeof(int) * count);
	if (!numbers)
		return (1);
	j = 1;
	while (j < ac)
	{
		validate_input(av[j]);
		if (validate_input(av[j]) == 1)
			free(&numbers);
		parse_int(av[j], &numbers);
		if (parse_int(av[j], numbers) == 1)
			free(&numbers);
		check_duplicates(&numbers, count);
		if (check_duplicates(&numbers, count) == 1)
			free(&numbers);
		j++;
	}
	return (0);
}
