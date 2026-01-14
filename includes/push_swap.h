/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 02:02:48 by gaeducas          #+#    #+#             */
/*   Updated: 2026/01/13 15:25:40 by gaeducas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	void			*content;
	struct s_node	*node;
	struct s_node	*next;
}					t_node;

int					validate_input(char *str);