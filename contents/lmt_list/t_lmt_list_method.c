/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_list_method.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:24:04 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/28 13:33:16 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_list.h"
#include "t_lmt_list_inner.h"

void	lmt_list_append(t_lmt_list *dummy, void *content)
{
	t_lmt_list	*element;

	element = lmt_list_new_core(content);
	element->prev = dummy->prev;
	element->next = dummy;
	element->prev->next = element;
	element->next->prev = element;
}
