/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:28:04 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/05/28 18:09:52 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*fill_array(t_node *stack, int size)
{
	int		*arr;
	int		i;
	t_node	*tmp;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	tmp = stack;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	return (arr);
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	assign_indexes(t_node *stack, int *arr, int size)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (i < size)
		{
			if (stack->value == arr[i])
			{
				stack->value = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
}

void	normalize_indexes(t_node *stack)
{
	int	*arr;
	int	size;

	size = stack_size(stack);
	arr = fill_array(stack, size);
	if (!arr)
		return ;
	sort_array(arr, size);
	assign_indexes(stack, arr, size);
	free(arr);
}

void	sort_large(t_stack *st)
{
	int	size;
	int	bits;
	int	i;
	int	j;

	normalize_indexes(st->a);
	size = stack_size(st->a);
	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((st->a->value >> i) & 1) == 0)
				op_pb(st);
			else
				op_ra(st);
		}
		while (st->b)
			op_pa(st);
		i++;
	}
}
