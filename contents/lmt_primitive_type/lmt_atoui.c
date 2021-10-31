/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_atoui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:40:38 by jeonpark          #+#    #+#             */
/*   Updated: 2021/11/01 13:23:07 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>	// UINT_MAX
#include "lmt_primitive_type.h"
#include "lmt_constant.h"	// PARSE_SUCCESS, PARSE_FAILURE

int	lmt_atoui(const char *str, unsigned int *number)
{
	unsigned long	temp_number;

	if (*str == '+')
		++str;
	if (!lmt_is_digit(*str))
		return (PARSE_FAILURE);
	while (*str == '0')
		++str;
	temp_number = 0;
	while (lmt_is_digit(*str))
	{
		temp_number = temp_number * 10 + (*str - '0');
		if (UINT_MAX < temp_number)
			return (PARSE_FAILURE);
		++str;
	}
	*number = temp_number;
	return (PARSE_SUCCESS);
}
