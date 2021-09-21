/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:43:14 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/21 20:08:09 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_util.h"
#include "lmt_constant.h"

///	- Assume: reading and writing p_result would be slower than
///		reading and writing result
static int	lmt_atol_parse_digit(char *string, long *p_result)
{
	long	result;

	while (*string == '0')
		++string;
	result = 0;
	while (lmt_is_digit(*string))
	{
		result = result * 10 + (*string - '0');
		if (result < 0)
			return (PARSE_FAILURE);
		++string;
	}
	if (*string == '\0')
	{
		*p_result = result;
		return (PARSE_SUCCESS);
	}
	else
		return (PARSE_FAILURE);
}

int	lmt_atol(char *string, long *p_result)
{
	int		sign;

	if (*string == '\0')
		return (PARSE_FAILURE);
	while (lmt_is_space(*string))
		++string;
	sign = 1 - (*string == '-') * 2;
	if (*string == '-' || *string == '+')
		++string;
	if (!lmt_is_digit(*string))
		return (PARSE_FAILURE);
	if (lmt_atol_parse_digit(string, p_result) == PARSE_FAILURE)
		return (PARSE_FAILURE);
	else
	{
		*p_result = sign * *p_result;
		return (PARSE_SUCCESS);
	}
}
