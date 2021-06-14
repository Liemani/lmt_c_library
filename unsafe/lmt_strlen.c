/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_strlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:00:57 by jeonpark          #+#    #+#             */
/*   Updated: 2021/06/14 22:43:48 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lmt_unsafe.h"

size_t	lmt_strlen(const char *string)
{
	const char	*p_ch;

	p_ch = string;
	while (*string != '\0')
		++p_ch;
	return (p_ch - string);
}
