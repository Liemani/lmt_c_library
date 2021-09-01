/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:43:14 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/18 13:59:17 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "lmt_util.h"

int	lmt_atoi(char *string, int *p_result)
{
	int		sign;
	long	result;

	if (*string == '\0')
		return (PARSE_FAILURE);
	while (lmt_is_space(*string))
		++string;
	if (*string == '-')
	{
		sign = -1;
		++string;
		if (lmt_is_digit(*string))
			return (PARSE_FAILURE);
	}
	else
	{
		sign = 1;
	}
	if (sign == -1 || *string == '+')
		++string;
	while (*string == '0')
		++string;
	result = 0;
	while (lmt_is_digit(*string))
	{
		result = result * 10 + (*string - '0');
		if (result > INT_MAX)
			return (PARSE_FAILURE);
		++string;
	}
	*p_result = sign * result;
	if (*string == '\0')
		return (PARSE_SUCCESS);
	return (PARSE_FAILURE);
}
