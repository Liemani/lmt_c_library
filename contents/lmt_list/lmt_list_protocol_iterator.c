/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_list_protocol_iterator.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:06:54 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/31 19:26:34 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_list.h"
#include "lmt_iterator.h"
#include "lmt_constant.h"	// NORMAL, ERROR

static void	*lmt_list_next(void *element)
{
	return (((t_lmt_list *)element)->next);
}

static void	*lmt_list_iterate_get_input(void *element)
{
	return (((t_lmt_list *)element)->content);
}

int	lmt_list_iterate_for_each(t_lmt_list *dummy,
		t_lmt_iterator_for_each function)
{
	t_lmt_iterator	*iter;

	if (dummy->next == dummy)
		return (NORMAL);
	iter = lmt_iterator_new(dummy->next, dummy->prev, lmt_list_next,
			lmt_list_iterate_get_input);
	if (iter == NULL)
		return (ERROR);
	if (lmt_iterator_for_each(iter, function) != NORMAL)
		return (ERROR);
	lmt_iterator_free(iter);
	return (NORMAL);
}

int	lmt_list_for_each_enumerated(t_lmt_list *dummy,
		t_lmt_iterator_for_each_enumerated function)
{
	t_lmt_iterator	*iter;

	if (dummy->next == dummy)
		return (NORMAL);
	iter = lmt_iterator_new(dummy->next, dummy->prev, lmt_list_next,
			lmt_list_iterate_get_input);
	if (iter == NULL)
		return (ERROR);
	if (lmt_iterator_for_each_enumerated(iter, function) != NORMAL)
		return (ERROR);
	lmt_iterator_free(iter);
	return (NORMAL);
}
