/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:56:19 by gaeducas          #+#    #+#             */
/*   Updated: 2026/01/16 10:09:23 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	return (0);
}

int	validate_input(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i] || !ft_isdigit(str[i]))
		return (ERROR);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	parse_int(char *str, int *result)
{
	long long	num;

	num = ft_atol(str);
	if (num < -2147483648LL || num > 2147483647LL)
	{
		ft_putstr_fd("Error\n", 2);
		return (ERROR);
	}
	*result = (int)num;
	return (SUCCESS);
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
				return (ERROR);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
