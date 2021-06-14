/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:43:14 by jeonpark          #+#    #+#             */
/*   Updated: 2021/06/14 22:49:32 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "util.h"

int			lmt_atoi(char *string, int *p_result)
{
	int		sign;
	long	result;

	if (*string == '\0')
		return (PARSE_FAIL);
	while (lmt_is_space(*string))
		++string;
	sign = (*string == '-' ? -1 : 1);
	if (sign == -1 || *string == '+')
		++string;
	while (*string == '0')
		++string;
	result = 0;
	while (lmt_is_digit(*string))
	{
		result = result * 10 + (*string - '0');
		if (result > INT_MAX)
		{
			*p_result = sign * result;
			return (PARSE_FAIL);
		}
		++string;
	}
	*p_result = sign * result;
	return (*string == '\0' ? PARSE_SUCCESSFUL : PARSE_FAIL);
}
