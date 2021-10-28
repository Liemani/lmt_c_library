/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_iterator_method.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:09:09 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/28 14:42:49 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// NULL, size_t
#include "t_lmt_iterator.h"

void	lmt_iterator_for_each(t_lmt_iterator *iter,
		t_lmt_iterator_for_each function)
{
	void	*element;

	if (!(iter != NULL && iter->first != NULL && function != NULL))
		return ;
	element = iter->first;
	while (element != iter->last)
	{
		function(iter->get_input(element));
		element = iter->next(element);
	}
	function(iter->get_input(element));
}

void	lmt_iterator_for_each_enumerated(t_lmt_iterator *iter,
		t_lmt_iterator_for_each_enumerated function)
{
	void	*element;
	size_t	index;

	if (!(iter != NULL && iter->first != NULL && function != NULL))
		return ;
	element = iter->first;
	index = 0;
	while (element != iter->last)
	{
		function(index, iter->get_input(element));
		element = iter->next(element);
		++index;
	}
	function(index, iter->get_input(element));
}
