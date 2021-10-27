/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_str_first_ch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:50:22 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 13:34:31 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// NULL
#include "lmt_primitive_type.h"

char	*lmt_str_first_ch(char *str, char ch)
{
	char	*output;

	if (!(str != NULL))
		return (NULL);
	output = str;
	while (*output != '\0')
	{
		if (*output == ch)
			return (output);
		++output;
	}
	if (ch != '\0')
		output = NULL;
	return (output);
}
