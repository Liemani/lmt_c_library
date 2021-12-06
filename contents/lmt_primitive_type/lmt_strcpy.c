/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_strcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:13:27 by jeonpark          #+#    #+#             */
/*   Updated: 2021/12/06 20:51:53 by jeonpark         ###   ########.fr       */
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
	*target = '\0';
	return (target);
}
