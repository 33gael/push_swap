/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:56:22 by gaeducas          #+#    #+#             */
/*   Updated: 2026/01/15 14:17:20 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	int	j;
	int	i;

	if (ac < 2)
		return (0);
	j = 1;
	while (j < ac)
	{
		i = 0;
		while (av[j][i])
		{
			validate_input(&av[j][i]);
			parse_int(&av[j][i]);
			i++;
		}
		j++;
	}
}
