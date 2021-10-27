/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:13:27 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 14:58:12 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// size_t, NULL
#include "lmt_primitive_type.h"
#include "lmt_alloc.h"	// lmt_alloc()

char	*lmt_strdup(const char *str)
{
	char	*output;

	if (str == NULL)
	{
		output = lmt_alloc(sizeof(*output) * 1);
		*output = '\0';
	}
	else
	{
		output = lmt_alloc(sizeof(*output) * (lmt_str_count(str) + 1));
		*lmt_strcpy(output, str) = '\0';
	}
	return (output);
}
