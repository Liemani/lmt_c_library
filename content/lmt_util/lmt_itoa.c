/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 23:19:28 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/01 15:02:34 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_util.h"

#define MAX_INT_LEN 10

static int	devide_10(unsigned int *p_number)
{
	return (*p_number /= 10);
}

char	*lmt_itoa(int n)
{
	unsigned int	positive_n;
	char			buffer[MAX_INT_LEN];
	char			*p_buffer_ch;
	char			*p_string;
	char			*p_string_ch;

	positive_n = ((n >= 0) * 2 - 1) * n;
	p_buffer_ch = buffer;
	*p_buffer_ch++ = '0' + (positive_n % 10);
	while (devide_10(&positive_n) != 0)
		*p_buffer_ch++ = '0' + (positive_n % 10);
	p_string = lmt_alloc(sizeof(char) * ((n < 0) + (p_buffer_ch - buffer) + 1));
	p_string_ch = p_string;
	if (n < 0)
		*p_string_ch++ = '-';
	while (p_buffer_ch != buffer)
		*p_string_ch++ = *(--p_buffer_ch);
	*p_string_ch = '\0';
	return (p_string);
}
