/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_iterator_method.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:09:09 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/31 19:30:05 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// NULL, size_t
#include "lmt_iterator.h"
#include "lmt_constant.h"	// NORMAL, ERROR

int	lmt_iterator_for_each(t_lmt_iterator *iter,
		t_lmt_iterator_for_each function)
{
	void	*element;

	if (!(iter != NULL && function != NULL))
		return (NORMAL);
	element = iter->first;
	while (element != iter->last)
	{
		if (function(iter->get_input(element)) != NORMAL)
			return (ERROR);
		element = iter->next(element);
	}
	if (function(iter->get_input(element)) != NORMAL)
		return (ERROR);
	return (NORMAL);
}

int	lmt_iterator_for_each_enumerated(t_lmt_iterator *iter,
		t_lmt_iterator_for_each_enumerated function)
{
	size_t	index;
	void	*element;

	if (!(iter != NULL && function != NULL))
		return (NORMAL);
	index = 0;
	element = iter->first;
	while (element != iter->last)
	{
		if (function(index, iter->get_input(element)) != NORMAL)
			return (ERROR);
		++index;
		element = iter->next(element);
	}
	if (function(index, iter->get_input(element)) != NORMAL)
		return (ERROR);
	return (NORMAL);
}
