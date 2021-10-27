/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_str_last_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:50:21 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 14:01:17 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// NULL
#include "lmt_primitive_type.h"

char	*lmt_str_last_str(char *str, const char *word)
{
	char	*output;

	if (!(str != NULL && word != NULL))
		return (NULL);
	output = str;
	while (*output != '\0')
		++output;
	while (str <= output)
	{
		if (lmt_str_has_prefix(output, word))
			return (output);
		--output;
	}
	return (NULL);
}
