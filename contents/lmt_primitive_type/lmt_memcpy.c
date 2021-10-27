/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_memcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:05:04 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 14:24:43 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// size_t, NULL
#include "lmt_primitive_type.h"
#include "lmt_constant.h"	// t_byte

void	*lmt_memcpy(void *target, const void *source, size_t size)
{
	if (!(target != NULL && source != NULL && size != 0))
		return (target);
	while (0 <= --size)
		((t_byte *)target)[size] = ((const t_byte *)source)[size];
	return (target);
}
