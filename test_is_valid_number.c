/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_valid_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:26:17 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/05/27 20:24:38 by jnovoa-a         ###   ########.fr       */
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

