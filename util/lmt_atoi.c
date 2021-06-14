/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:43:14 by jeonpark          #+#    #+#             */
/*   Updated: 2021/06/14 21:54:44 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "util.h"

int			lmt_atoui(char *string, int *p_result)
{
	int				sign;
	unsigned int	result;

	if (*string == '\0')
		return (PARSE_FAIL);
	while (lmt_is_space(*string))
		++string;
	sign = (*str == '-' ? -1 : 1);
	if (sign == -1 || *str == '+')
		++str;
	while (*string == '0')
		++string;
	result = 0;
	while (is_digit(*string))
	{
		result = result * 10 + (*string - '0');
		if (result < INT_MIN || result > INT_MAX)
		{
			*p_result = sign * result;
			return (PARSE_FAIL);
		}
		++string;
	}
	*p_result = sign * result;
	return (*string == '\0' ? PARSE_SUCCESSFUL : PARSE_FAIL);
}
