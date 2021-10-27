/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_byte_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:05:04 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 21:50:09 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// size_t, NULL
#include "lmt_primitive_type.h"
#include "lmt_constant.h"	// t_lmt_byte

void	*lmt_byte_cpy(void *target, const void *source, size_t size)
{
	size_t	index;

	if (!(target != NULL && source != NULL))
		return (target);
	index = 0;
	while (index < size)
	{
		((t_lmt_byte *)target)[index] = ((const t_lmt_byte *)source)[index];
		++index;
	}
	return (target);
}
