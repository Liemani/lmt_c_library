/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_byte_equals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:59:46 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 21:53:02 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// size_t
#include "lmt_primitive_type.h"
#include "lmt_constant.h"	// TRUE, FALSE

int	lmt_byte_equals(const void *lhs, const void *rhs, size_t count)
{
	size_t	index;

	if (!(lhs != NULL && rhs != NULL))
		return (FALSE);
	index = 0;
	while (index < count)
	{
		if (((const t_lmt_byte *)lhs)[index]
				!= ((const t_lmt_byte *)rhs)[index])
			return (FALSE);
		++index;
	}
	return (TRUE);
}
