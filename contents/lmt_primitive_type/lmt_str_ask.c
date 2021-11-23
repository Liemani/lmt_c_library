/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_str_ask.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:42:52 by jeonpark          #+#    #+#             */
/*   Updated: 2021/11/23 11:51:39 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// NULL
#include "lmt_primitive_type.h"
#include "lmt_constant.h"	// TRUE, FALSE

int	lmt_str_equals(const char *lhs, const char *rhs)
{
	if (!(lhs != NULL && rhs != NULL))
		return (FALSE);
	while (*rhs != '\0')
		if (*lhs++ != *rhs++)
			return (FALSE);
	if (*lhs != '\0')
		return (FALSE);
	return (TRUE);
}

int	lmt_str_has_prefix(const char *str, const char *word)
{
	if (!(str != NULL && word != NULL))
		return (FALSE);
	while (*word != '\0')
		if (*str++ != *word++)
			return (FALSE);
	return (TRUE);
}
