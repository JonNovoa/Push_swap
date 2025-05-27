/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:08:34 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/05/27 13:37:20 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *st)
{
	t_node	*tmp;

	if (!st || !st->b)
		return ;
	tmp = st->b;
	st->b = st->b->next;
	tmp->next = st->a;
	st->a = tmp;
}

void	push_b(t_stack *st)
{
	t_node	*tmp;

	if (!st || !st->a)
		return ;
	tmp = st->a;
	st->a = st->a->next;
	tmp->next = st->b;
	st->b = tmp;
}

void	op_pa(t_stack *st)
{
	push_a(st);
	write(1, "pa\n", 3);
}

void	op_pb(t_stack *st)
{
	push_b(st);
	write(1, "pb\n", 3);
}
