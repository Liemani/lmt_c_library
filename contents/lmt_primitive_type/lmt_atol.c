/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:43:14 by jeonpark          #+#    #+#             */
/*   Updated: 2021/11/23 11:51:39 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>	// LONG_MAX, LONG_MIN
#include "lmt_primitive_type.h"
#include "lmt_constant.h"

static int	lmt_atol_positive(const char *str, long *number)
{
	if (*str == '+')
		++str;
	if (!lmt_is_digit(*str))
		return (PARSE_FAILURE);
	while (*str == '0')
		++str;
	*number = 0;
	while (lmt_is_digit(*str))
	{
		if ((LONG_MAX - (*str - '0')) / 10 < *number)
			return (PARSE_FAILURE);
		*number = *number * 10 + (*str - '0');
		++str;
	}
	return (PARSE_SUCCESS);
}

static int	lmt_atol_negative(const char *str, long *number)
{
	if (*str != '-')
		return (PARSE_FAILURE);
	++str;
	if (!lmt_is_digit(*str))
		return (PARSE_FAILURE);
	while (*str == '0')
		++str;
	*number = 0;
	while (lmt_is_digit(*str))
	{
		if (*number < (LONG_MIN + (*str - '0')) / 10)
			return (PARSE_FAILURE);
		*number = *number * 10 - (*str - '0');
		++str;
	}
	return (PARSE_SUCCESS);
}

int	lmt_atol(const char *str, long *number)
{
	long	temp_number;

	if (*str == '-')
	{
		if (lmt_atol_negative(str, &temp_number) != PARSE_SUCCESS)
			return (PARSE_FAILURE);
	}
	else
	{
		if (lmt_atol_positive(str, &temp_number) != PARSE_SUCCESS)
			return (PARSE_FAILURE);
	}
	*number = temp_number;
	return (PARSE_SUCCESS);
}
