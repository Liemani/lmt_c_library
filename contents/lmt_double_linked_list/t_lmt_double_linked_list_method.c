/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_double_linked_list_method.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:24:04 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/14 14:37:30 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_double_linked_list.h"

void	lmt_double_linked_list_put_next(t_lmt_double_linked_list *list,
		t_lmt_double_linked_list *element)
{
	element->next = list->next;
	element->prev = list;
	list->next = element;
	if (element->next != NULL)
		element->next->prev = element;
}
