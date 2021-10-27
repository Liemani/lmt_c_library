/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_str_last_ch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:51:16 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 13:59:35 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_primitive_type.h"

char	*lmt_str_last_ch(char *str, char ch)
{
	char	*output;

	if (!(str != NULL))
		return (NULL);
	output = str;
	while (*output != '\0')
		++output;
	while (str <= output)
	{
		if (*output == ch)
			return (output);
		--output;
	}
	return (NULL);
}
