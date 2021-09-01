/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_atoui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:40:38 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/18 13:59:02 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "lmt_util.h"

int	lmt_atoui(char *string, unsigned int *p_result)
{
	unsigned long	result;

	if (*string == '\0')
		return (PARSE_FAILURE);
	while (lmt_is_space(*string))
		++string;
	while (*string == '0')
		++string;
	result = 0;
	while (lmt_is_digit(*string))
	{
		result = result * 10 + (*string - '0');
		if (result > UINT_MAX)
		{
			*p_result = result;
			return (PARSE_FAILURE);
		}
		++string;
	}
	*p_result = result;
	if (*string == '\0')
		return (PARSE_SUCCESS);
	return (PARSE_FAILURE);
}
