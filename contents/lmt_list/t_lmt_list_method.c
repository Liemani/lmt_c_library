/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_list_method.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:24:04 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/28 12:00:35 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_list.h"

void	lmt_list_append(t_lmt_list *dummy, t_lmt_list *element)
{
	element->prev = dummy->prev;
	element->next = dummy;
	element->prev->next = element;
	element->next->prev = element;
}
