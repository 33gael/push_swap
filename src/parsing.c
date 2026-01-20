/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:56:19 by gaeducas          #+#    #+#             */
/*   Updated: 2026/01/20 14:36:41 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_syntax(char *str)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			break ;
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (!ft_isdigit(str[i]))
			return (ERROR);
		while (ft_isdigit(str[i]))
		{
			has_digit = 1;
			i++;
		}
		if (str[i] && str[i] != ' ')
			return (ERROR);
	}
	return (has_digit);
}

int	count_args(int ac, char **av)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 1;
	while (i < ac)
	{
		if (check_syntax(av[i]) == ERROR)
			return (ERROR);
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] == ' ')
				j++;
			if (av[i][j])
				count++;
			while (av[i][j] && av[i][j] != ' ')
				j++;
		}
		i++;
	}
	return (count);
}

static int	parse_token(char *str, int *numbers, int *k)
{
	int			j;
	long long	tmp;

	j = 0;
	while (str[j])
	{
		while (str[j] == ' ')
			j++;
		if (str[j] == '\0')
			break ;
		tmp = ft_atol(&str[j]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (ERROR);
		numbers[(*k)++] = (int)tmp;
		while (str[j] && str[j] != ' ')
			j++;
	}
	return (SUCCESS);
}

int	get_numbers(int ac, char **av, int *numbers)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (i < ac)
	{
		if (parse_token(av[i], numbers, &k) == ERROR)
			return (ERROR);
		i++;
	}
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
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
