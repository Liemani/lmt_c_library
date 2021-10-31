/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_list_method.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:24:04 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/31 14:34:13 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_list.h"
#include "t_lmt_list_static.h"
#include "lmt_constant.h"	// NORMAL, ERROR

int	lmt_list_append(t_lmt_list *dummy, void *content)
{
	t_lmt_list	*element;

	if (!(content != NULL))
		return (NORMAL);
	element = lmt_list_new_static(content);
	if (element == NULL)
		return (ERROR);
	element->prev = dummy->prev;
	element->next = dummy;
	element->prev->next = element;
	element->next->prev = element;
	return (NORMAL);
}
