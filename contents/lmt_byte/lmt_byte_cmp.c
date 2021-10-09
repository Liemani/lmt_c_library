/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_byte_cmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:59:46 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/09 15:32:53 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// size_t
#include "t_lmt_byte.h"
#include "lmt_constant.h"

///	- parameters:
///		- lhs: non-optional
///		- rhs: non-optional
int	lmt_byte_cmp(const t_lmt_byte *lhs, const t_lmt_byte *rhs, size_t count)
{
	while (count > 0)
	{
		if (*lhs++ != *rhs++)
			return (FALSE);
		--count;
	}
	return (TRUE);
}
