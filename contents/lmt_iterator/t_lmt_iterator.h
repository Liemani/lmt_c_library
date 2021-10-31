/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_iterator.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:47:26 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/31 16:04:39 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_ITERATOR_H
# define T_LMT_ITERATOR_H

# include <stddef.h>	// size_t

typedef void *	(*t_lmt_iterator_next)(void *element);
typedef void *	(*t_lmt_iterator_for_each_get_input)(void *element);
typedef int		(*t_lmt_iterator_for_each)(void *element);
typedef int		(*t_lmt_iterator_for_each_enumerated)(
		size_t index, void *element);

///	- properties:
///		- first: optional
///		- last: optional
///			- If first is NULL, last is must NULL
///		- next: non-optional
///			- Must be able to get last by Iterating next
///		- get_input: non-optional
///			- If the get_input of lmt_iterator_new() is NULL,
///				default identity_function will be set
typedef struct s_lmt_iterator
{
	void								*first;
	void								*last;
	t_lmt_iterator_next					next;
	t_lmt_iterator_for_each_get_input	get_input;
}	t_lmt_iterator;

///	- return value:
///		- NULL: If next is NULL or if malloc fail
t_lmt_iterator	*lmt_iterator_new(void *first, void *last,
					t_lmt_iterator_next next,
					t_lmt_iterator_for_each_get_input get_input);
void			lmt_iterator_free(t_lmt_iterator *iter);

///	- for each function: Don't free element or move position of element
///		in the argument function.
int				lmt_iterator_for_each(t_lmt_iterator *iter,
					t_lmt_iterator_for_each function);
int				lmt_iterator_for_each_enumerated(t_lmt_iterator *iter,
					t_lmt_iterator_for_each_enumerated function);

#endif
