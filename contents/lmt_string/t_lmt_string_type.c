/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_string_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:02:54 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/30 16:21:39 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// free(), NULL
#include "t_lmt_string.h"
#include "lmt_alloc.h"
#include "lmt_primitive_type.h"

static t_lmt_string	*lmt_string_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_string)));
}

void	lmt_string_init(t_lmt_string *string, const char *str)
{
	if (str == NULL)
		str = "";
	string->str = lmt_strdup(str);
	string->count = lmt_str_count(str);
}

t_lmt_string	*lmt_string_new(const char *str)
{
	t_lmt_string	*string;

	string = lmt_string_alloc();
	lmt_string_init(string, str);
	return (string);
}

void	lmt_string_free(t_lmt_string *string)
{
	free(string->str);
	free(string);
}
