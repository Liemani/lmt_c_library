/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_string_static_constructor.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:33:58 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/31 14:17:06 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// malloc(), NULL
#include "t_lmt_string_static.h"
#include "t_lmt_string.h"
#include "lmt_primitive_type.h"
#include "lmt_constant.h"	// NORMAL, ERROR

t_lmt_string	*lmt_string_alloc(void)
{
	return (malloc(sizeof(t_lmt_string)));
}

int	lmt_string_init(t_lmt_string *string, const char *str)
{
	if (str == NULL)
		str = "";
	string->str = lmt_strdup(str);
	if (string->str == NULL)
		return (ERROR);
	string->count = lmt_str_count(str);
	return (NORMAL);
}
