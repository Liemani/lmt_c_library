/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:43:14 by jeonpark          #+#    #+#             */
/*   Updated: 2021/11/01 13:34:18 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>	// INT_MAX, INT_MIN
#include "lmt_primitive_type.h"
#include "lmt_constant.h"

static int	lmt_atoi_positive(const char *str, long *wide_number)
{
	if (*str == '+')
		++str;
	if (!lmt_is_digit(*str))
		return (PARSE_FAILURE);
	while (*str == '0')
		++str;
	*wide_number = 0;
	while (lmt_is_digit(*str))
	{
		*wide_number = *wide_number * 10 + (*str - '0');
		if (INT_MAX < *wide_number)
			return (PARSE_FAILURE);
		++str;
	}
	return (PARSE_SUCCESS);
}

static int	lmt_atoi_negative(const char *str, long *wide_number)
{
	if (*str != '-')
		return (PARSE_FAILURE);
	++str;
	if (!lmt_is_digit(*str))
		return (PARSE_FAILURE);
	while (*str == '0')
		++str;
	*wide_number = 0;
	while (lmt_is_digit(*str))
	{
		*wide_number = *wide_number * 10 - (*str - '0');
		if (*wide_number < INT_MIN)
			return (PARSE_FAILURE);
		++str;
	}
	return (PARSE_SUCCESS);
}

int	lmt_atoi(const char *str, int *number)
{
	long	wide_number;

	if (*str == '-')
	{
		if (lmt_atoi_negative(str, &wide_number) != PARSE_SUCCESS)
			return (PARSE_FAILURE);
	}
	else
	{
		if (lmt_atoi_positive(str, &wide_number) != PARSE_SUCCESS)
			return (PARSE_FAILURE);
	}
	*number = wide_number;
	return (PARSE_SUCCESS);
}
