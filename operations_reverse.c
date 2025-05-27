/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:36:44 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/05/27 13:49:30 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *st)
{
	t_node	*prev;
	t_node	*last;

	if (!st || !st->a || !st->a->next)
		return ;
	prev = NULL;
	last = st->a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = st->a;
	st->a = last;	
}

void	op_rra(t_stack *st)
{
	reverse_rotate_a(st);
	write(1, "rra\n",4);
}

void	op_rrb(t_stack *st)
{
	reverse_rotate_b(st);
	write(1, "rrb\n",4);
}

void	op_rrr(t_stack *st)
{
	reverse_rotate_a(st);
	reverse_rotate_b(st);
	write(1, "rrr\n",4);
}