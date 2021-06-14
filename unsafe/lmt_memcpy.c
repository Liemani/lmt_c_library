/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_memcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:05:04 by jeonpark          #+#    #+#             */
/*   Updated: 2021/06/14 22:30:26 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lmt_unsafe.h"

void	*lmt_memcpy(void *p_write, const void *p_read, size_t size)
{
	while (size != 0)
	{
		*p_write++ = *p_read++;
		--size;
	}
	return (p_write);
}
