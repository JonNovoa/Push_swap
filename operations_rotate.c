/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:51:14 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/05/27 15:02:12 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *st)
{
	t_node	*first;
	t_node	*last;

	if (!st || !st->a || !st->a->next)
		return ;
	first = st->a;
	st->a = first->next;
	first->next = NULL;
	last = st->a;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	rotate_b(t_stack *st)
{
	t_node	*first;
	t_node	*last;

	if (!st || !st->b || !st->b->next)
		return ;
	first = st->b;
	st->b = first->next;
	first->next = NULL;
	last = st->b;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	op_ra(t_stack *st)
{
	rotate_a(st);
	write(1, "ra\n", 3);
}

void	op_rb(t_stack *st)
{
	rotate_b(st);
	write(1, "rb\n", 3);
}

void	op_rr(t_stack *st)
{
	rotate_a(st);
	rotate_b(st);
	write(1, "rr\n", 3);
}
