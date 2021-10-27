/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_str_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:00:57 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 13:47:20 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// size_t, NULL
#include "lmt_primitive_type.h"

size_t	lmt_str_count(const char *str)
{
	const char	*ptr;

	if (!(str != NULL))
		return (0);
	ptr = str;
	while (*ptr != '\0')
		++ptr;
	return (ptr - str);
}
