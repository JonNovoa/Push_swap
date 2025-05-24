/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:13:32 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/05/24 21:32:06 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sb(t_stack *st)
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
	write(1, "sb\n", 3);
}
