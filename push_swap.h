/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:26:17 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/05/23 18:38:31 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
}	t_stack;

int		is_valid_number(char *str);
int		is_duplicate(t_node *stack, int value);
void	append_node(t_node **stack, int value);
void	exit_error(t_node **a, t_node **b);
void	free_stack(t_node **stack);
void	op_sa(t_stack *st);
void	op_sb(t_stack *st);
void	op_ss(t_stack *st);
void	op_pa(t_stack *st);
void	op_pb(t_stack *st);
void	op_ra(t_stack *st);
void	op_rb(t_stack *st);
void	op_rr(t_stack *st);
void	op_rra(t_stack *st);
void	op_rrb(t_stack *st);
void	op_rrr(t_stack *st);
void	sort_small(t_stack *st, int count);
void	sort_large(t_stack *st, int count);

#endif
