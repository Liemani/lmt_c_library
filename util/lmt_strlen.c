/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_strlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:00:57 by jeonpark          #+#    #+#             */
/*   Updated: 2021/06/14 22:02:31 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "util.h"

size_t	lmt_strlen(const char *string)
{
	const char	*p_ch;

	p_ch = string;
	while (*string != '\0')
		++p_ch;
	return (p_ch - string);
}
