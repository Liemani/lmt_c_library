/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_string_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:02:54 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/31 19:28:02 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// free()
#include "lmt_string.h"
#include "lmt_string_static.h"
#include "lmt_constant.h"	// NORMAL, ERROR

t_lmt_string	*lmt_string_new(const char *str)
{
	t_lmt_string	*string;

	string = lmt_string_alloc();
	if (string == NULL)
		return (NULL);
	if (lmt_string_init(string, str) != NORMAL)
		return (NULL);
	return (string);
}

void	lmt_string_free(t_lmt_string *string)
{
	free(string->str);
	free(string);
}
