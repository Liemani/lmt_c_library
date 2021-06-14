/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_memcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:05:04 by jeonpark          #+#    #+#             */
/*   Updated: 2021/06/14 22:43:48 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lmt_unsafe.h"

void	*lmt_memcpy(void *p_write, const void *p_read, size_t size)
{
	while (size != 0)
	{
		*(unsigned char *)p_write++ = *(const unsigned char *)p_read++;
		--size;
	}
	return (p_write);
}
