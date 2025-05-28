/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:19:15 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/05/28 18:15:23 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	int	sign;
	int	i;

	if (!valid_format(str, &sign, &i))
		return (0);
	if (!is_digit_str(str + i))
		return (0);
	if (!within_limits(str, sign, &i))
		return (0);
	return (1);
}

int	is_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack ->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	append_node(t_node **stack, int value)
{
	t_node	*new_node;
	t_node	*tmp;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

void	exit_error(t_node **a, t_node **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
