/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:27:50 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/05/28 15:08:51 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *st)
{
	int	a;
	int	b;
	int	c;

	a = st->a->value;
	b = st->a->next->value;
	c = st->a->next->next->value;
	if (a > b && b < c && a < c)
		op_sa(st);
	else if (a > b && b > c)
	{
		op_sa(st);
		op_rra(st);
	}
	else if (a > b && b < c && a > c)
		op_ra(st);
	else if (a < b && b > c && a < c)
	{
		op_sa(st);
		op_ra(st);
	}
	else if (a < b && b > c && a > c)
		op_rra(st);
}

void	sort_small(t_stack *st)
{
	int	min_pos;

	if (stack_size(st->a) == 2)
	{
		if (st->a->value > st->a->next->value)
			op_sa(st);
	}
	else if (stack_size(st->a) == 3)
	{
		sort_three(st);
	}
	else
	{
		while (stack_size(st->a) > 3)
		{
			min_pos = get_position(st->a, get_min(st->a));
			while (min_pos--)
				op_ra(st);
			op_pb(st);
		}
		sort_three(st);
		while (st->b)
			op_pa(st);
	}
}
