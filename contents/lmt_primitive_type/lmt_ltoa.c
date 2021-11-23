/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_ltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 23:19:28 by jeonpark          #+#    #+#             */
/*   Updated: 2021/11/23 11:51:39 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// malloc(), NULL
#include "lmt_primitive_type.h"
#include "lmt_constant.h"	// MAX_LONG_LENGTH

static unsigned long	lmt_ltoa_devide_10(unsigned long *number)
{
	*number /= 10;
	return (*number);
}

char	*lmt_ltoa(long number)
{
	unsigned long	positive_number;
	char			buffer[MAX_LONG_LENGTH];
	char			*p_buffer;
	char			*str;
	char			*p_str;

	positive_number = ((number >= 0) * 2 - 1) * number;
	p_buffer = buffer;
	*p_buffer++ = '0' + (positive_number % 10);
	while (lmt_ltoa_devide_10(&positive_number) != 0)
		*p_buffer++ = '0' + (positive_number % 10);
	str = malloc((number < 0) + (p_buffer - buffer) + 1);
	if (str == NULL)
		return (NULL);
	p_str = str;
	if (number < 0)
		*p_str++ = '-';
	while (p_buffer != buffer)
		*p_str++ = *(--p_buffer);
	*p_str = '\0';
	return (str);
}
