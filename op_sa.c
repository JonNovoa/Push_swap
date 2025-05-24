/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:06:52 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/05/24 21:31:46 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_stack *st)
{
	t_node	*first;
	t_node	*second;

	if (!st || !st->a || !st->a->next)
	{
		return ;
	}
	first = st->a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	st->a = second;
	write(1, "sa\n", 3);
}
