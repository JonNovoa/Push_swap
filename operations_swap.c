/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 00:00:00 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/05/27 20:15:47 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *st)
{
	t_node	*first;
	t_node	*second;

	if (!st || !st->a || !st->a->next)
		return ;
	first = st->a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	st->a = second;
}

void	swap_b(t_stack *st)
{
	t_node	*first;
	t_node	*second;

	if (!st || !st->b || !st->b->next)
		return ;
	first = st->b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	st->b = second;
}

void	op_sa(t_stack *st)
{
	swap_a(st);
	write (1, "sa\n", 3);
}

void	op_sb(t_stack *st)
{
	swap_b(st);
	write (1, "sb\n", 3);
}

void	op_ss(t_stack *st)
{
	swap_a(st);
	swap_b(st);
	write(1, "ss\n", 3);
}
