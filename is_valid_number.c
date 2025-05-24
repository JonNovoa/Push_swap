/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:26:17 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/05/24 21:26:05 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_format(const char *s, int *sign, int *i)
{
	*sign = 1;
	*i = 0;
	if (!s || !s[0])
		return (0);
	if (s[0] == '-' || s[0] == '+')
	{
		if (!s[1])
			return (0);
		if (s[0] == '-')
			*sign = -1;
		(*i)++;
	}
	return (1);
}

static int	is_digit_str(const char *s)
{
	int	j;

	j = 0;
	while (s[j])
	{
		if (!ft_isdigit(s[j]))
			return (0);
		j++;
	}
	return (1);
}

static int	within_limits(const char *s, int sign, int i)
{
	long	num;

	num = 0;
	while (s[i])
	{
		num = num * 10 + (s[i] - '0');
		if ((sign == 1 && num > INT_MAX)
			|| (sign == -1 && - num < INT_MIN))
			return (0);
		i++;
	}
	return (1);
}

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
