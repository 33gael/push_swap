/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:56:22 by gaeducas          #+#    #+#             */
/*   Updated: 2026/01/13 15:03:30 by gaeducas         ###   ########.fr       */
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
			if (av[j][i] < '0' || av[j][i] > '9')
			{
				ft_putstr_fd("Error you can only use numbers\n", 2);
				return (1);
			}
			i++;
		}
		j++;
	}
}
