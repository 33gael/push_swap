/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:09:30 by gaeducas          #+#    #+#             */
/*   Updated: 2026/01/14 09:50:52 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long int	ft_atol(const char *str)
{
	int			i;
	long int	res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] >= 0 && str[i] <= 9)
		res = res * 10 + (str[i] - 48);
	return (res * sign);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
