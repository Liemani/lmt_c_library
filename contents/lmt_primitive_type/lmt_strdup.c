/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:13:27 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/31 14:15:20 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// malloc(), NULL
#include "lmt_primitive_type.h"

char	*lmt_strdup(const char *str)
{
	char	*output;

	if (str == NULL)
	{
		output = malloc(sizeof(*output) * 1);
		if (output == NULL)
			return (NULL);
		*output = '\0';
	}
	else
	{
		output = malloc(sizeof(*output) * (lmt_str_count(str) + 1));
		if (output == NULL)
			return (NULL);
		*lmt_strcpy(output, str) = '\0';
	}
	return (output);
}
