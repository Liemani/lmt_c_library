/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_iterator.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:47:26 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/28 12:07:42 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_ITERATOR_H
# define T_LMT_ITERATOR_H

# include <stddef.h>	// size_t

typedef void *	(*t_lmt_iterator_next)(void *element);
typedef void	(*t_lmt_iterator_for_each)(void *element);
typedef void	(*t_lmt_iterator_enumerated_for_each)(
		size_t index, void *element);

///	- properties:
///		- first: optional
///		- last: optional
typedef struct s_lmt_iterator
{
	void				*first;
	void				*last;
	t_lmt_iterator_next	next;
}	t_lmt_iterator;

///	- type function
t_lmt_iterator	*lmt_iterator_new(void *first, void *last,
					t_lmt_iterator_next next);
void			lmt_iterator_free(t_lmt_iterator *iter);

///	- for each function: Don't free element or move position of element
///		in the function.
void			lmt_iterator_for_each(t_lmt_iterator *iter,
					t_lmt_iterator_for_each function);
void			lmt_iterator_enumerated_for_each(t_lmt_iterator *iter,
					t_lmt_iterator_enumerated_for_each function);

#endif
