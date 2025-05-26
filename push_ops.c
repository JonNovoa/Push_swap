/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jon <jon@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:08:34 by jon               #+#    #+#             */
/*   Updated: 2025/05/26 14:13:58 by jon              ###   ########.fr       */
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
