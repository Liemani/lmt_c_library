/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_strlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:00:57 by jeonpark          #+#    #+#             */
/*   Updated: 2021/06/15 10:09:36 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lmt_unsafe.h"

size_t	lmt_strlen(const char *p_string)
{
	const char	*p_string_ch;

	p_string_ch = p_string;
	while (*p_string_ch != '\0')
		++p_string_ch;
	return (p_string_ch - p_string);
}
