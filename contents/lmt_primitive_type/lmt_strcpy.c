/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_strcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:13:27 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 14:58:12 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// NULL
#include "lmt_primitive_type.h"

char	*lmt_strcpy(char *target, const char *source)
{
	if (!(target != NULL && source != NULL))
		return (target);
	while (*source != '\0')
		*target++ = *source++;
	return (target);
}
