/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:56:19 by gaeducas          #+#    #+#             */
/*   Updated: 2026/01/14 10:26:38 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	validate_input(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i] || !ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
			i++;
		}
		return (1);
	}
}
int	parse_int(char *str)
{
	int	*res;
	int	i;

	i = 0;
	while (str[i])
		res = ft_atol(str);
	if (str[i] < -2147483648 && str[i] > 2147483647)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	else
		return (1);
}

int	check_duplicates(int *nb, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (nb[i] == nb[j])
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
