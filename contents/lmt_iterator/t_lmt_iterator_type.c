/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_iterator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:47:27 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/30 16:49:44 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// free()
#include "t_lmt_iterator.h"
#include "lmt_alloc.h"

static void	*identity_function(void *input)
{
	return (input);
}

static t_lmt_iterator	*lmt_iterator_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_iterator)));
}

static void	lmt_iterator_init(t_lmt_iterator *iter, void *first, void *last,
		t_lmt_iterator_next next)
{
	iter->first = first;
	iter->last = last;
	iter->next = next;
}

t_lmt_iterator	*lmt_iterator_new(void *first, void *last,
		t_lmt_iterator_next next,
		t_lmt_iterator_for_each_get_input get_input)
{
	t_lmt_iterator	*iter;

	iter = lmt_iterator_alloc();
	lmt_iterator_init(iter, first, last, next);
	if (get_input != NULL)
		iter->get_input = get_input;
	else
		iter->get_input = identity_function;
	return (iter);
}

void	lmt_iterator_free(t_lmt_iterator *iter)
{
	free(iter);
}
