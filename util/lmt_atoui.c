/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_atoui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:40:38 by jeonpark          #+#    #+#             */
/*   Updated: 2021/06/14 21:37:00 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "util.h"

static int	is_digit(char ch)
{
	return ('0' <= ch && ch <= '9');
}

int			lmt_atoui(char *string, unsigned int *p_result)
{
	unsigned long	result;

	while (*string == '0')
		++string;
	result = 0;
	while (is_digit(*string))
	{
		result = result * 10 + (*string - '0');
		if (result >= UINT_MAX)
		{
			*p_result = result;
			return (PARSE_FAIL);
		}
		++string;
	}
	*p_result = result;
	return (*string == '\0' ? PARSE_SUCCESSFUL : PARSE_FAIL);
}
