/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_list_protocol_iterator.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:06:54 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/31 16:17:14 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_list.h"
#include "t_lmt_iterator.h"

static void	*lmt_list_next(void *element)
{
	return (((t_lmt_list *)element)->next);
}

static void	*lmt_list_iterate_get_input(void *element)
{
	return (((t_lmt_list *)element)->content);
}

void	lmt_list_iterate_for_each(t_lmt_list *dummy,
		t_lmt_iterator_for_each function)
{
	t_lmt_iterator	*iter;

	if (dummy->next == dummy)
		return ;
	iter = lmt_iterator_new(dummy->next, dummy->prev, lmt_list_next,
			lmt_list_iterate_get_input);
	lmt_iterator_for_each(iter, function);
	lmt_iterator_free(iter);
}

void	lmt_list_for_each_enumerated(t_lmt_list *dummy,
		t_lmt_iterator_for_each_enumerated function)
{
	t_lmt_iterator	*iter;

	if (dummy->next == dummy)
		return ;
	iter = lmt_iterator_new(dummy->next, dummy->prev, lmt_list_next,
			lmt_list_iterate_get_input);
	lmt_iterator_for_each_enumerated(iter, function);
	lmt_iterator_free(iter);
}
