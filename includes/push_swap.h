/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 02:02:48 by gaeducas          #+#    #+#             */
/*   Updated: 2026/01/19 15:23:22 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define SUCCESS 1
# define ERROR 0

typedef struct s_node
{
	int				value;
	int				index;
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
void				free_stack(t_node **stack);
t_node				*init_stack(int *numbers, int count);
int					stack_size(t_node *stack);
int					is_sorted(t_node *stack);
void				error_exit(void);
void				sa(t_node **stack_a);
void				sb(t_node **stack_b);
void				ss(t_node **stack_a, t_node **stack_b);
void				pa(t_node **stack_a, t_node **stack_b);
void				pb(t_node **stack_a, t_node **stack_b);
void				ra(t_node **stack_a);
void				rb(t_node **stack_b);
void				rr(t_node **stack_a, t_node **stack_b);
void				rra(t_node **stack_a);
void				rrb(t_node **stack_b);
void				rrr(t_node **stack_a, t_node **stack_b);
void				sort_three(t_node **a);
void				sort_five(t_node **a, t_node **b);
void				butterfly_sort(t_node **a, t_node **b);
void				index_stack(t_node **stack);

#endif