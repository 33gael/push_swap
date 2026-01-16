/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 02:02:48 by gaeducas          #+#    #+#             */
/*   Updated: 2026/01/16 14:36:49 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define SUCCESS 1
# define ERROR 0

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

int					validate_input(char *str);
int					parse_int(char *str, int *result);
long long			ft_atol(const char *str);
void				ft_putstr_fd(char *s, int fd);
int					ft_isdigit(int c);
int					check_duplicates(int *nb, int len);
t_node				*create_node(int value);
void				stack_add_back(t_node **stack, t_node *new_node);

#endif