/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 02:02:48 by gaeducas          #+#    #+#             */
/*   Updated: 2026/01/15 15:19:53 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	void			*content;
	struct s_node	*node;
	struct s_node	*next;
}					t_node;

int					validate_input(char *str);
int					parse_int(char *str, int *result);
long long			ft_atol(const char *str);
void				ft_putstr_fd(char *s, int fd);
int					ft_isdigit(int c);
int					check_duplicates(int *nb, int len);

#endif