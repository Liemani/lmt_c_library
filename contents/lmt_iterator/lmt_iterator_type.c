/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_iterator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:47:27 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/31 19:30:25 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// malloc(), free(), NULL
#include "lmt_iterator.h"

static void	*identity_function(void *input)
{
	return (input);
}

static t_lmt_iterator	*lmt_iterator_alloc(void)
{
	return (malloc(sizeof(t_lmt_iterator)));
}

static void	lmt_iterator_init(t_lmt_iterator *iter,
		void *first, void *last,
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

	if ((first == NULL && last != NULL) || !(next != NULL))
		return (NULL);
	iter = lmt_iterator_alloc();
	if (iter == NULL)
		return (NULL);
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
