/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_iterator_method.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:09:09 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 20:27:10 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// NULL, size_t
#include "t_lmt_iterator.h"

void	lmt_iterator_for_each(t_lmt_iterator *iter,
		t_lmt_iterator_for_each function)
{
	void	*element;

	if (iter->first == NULL)
		return ;
	element = iter->first;
	while (element != iter->last)
	{
		function(element);
		element = iter->next(element);
	}
	function(element);
}

void	lmt_iterator_enumerated_for_each(t_lmt_iterator *iter,
		t_lmt_iterator_enumerated_for_each function)
{
	void	*element;
	size_t	index;

	if (iter->first == NULL)
		return ;
	element = iter->first;
	index = 0;
	while (element != iter->last)
	{
		function(index, element);
		element = iter->next(element);
		++index;
	}
	function(index, element);
}
