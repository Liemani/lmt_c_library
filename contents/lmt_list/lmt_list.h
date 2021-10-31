/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:54:33 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/31 19:26:16 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_LIST_H
# define LMT_LIST_H

# include "lmt_iterator.h"	// protocol

typedef void	(*t_lmt_list_free_content)(void *content);

///	- description: circular double linked list
///	- property:
///		- content: non-optional except dummy
///		- prev: non-optional
///		- next: non-optional
typedef struct s_lmt_list
{
	void				*content;
	struct s_lmt_list	*prev;
	struct s_lmt_list	*next;
}	t_lmt_list;

///	- constructor
t_lmt_list	*lmt_list_new(void);

///	- deconstructor
void		lmt_list_free_element(t_lmt_list *element,
				t_lmt_list_free_content free_content);
void		lmt_list_free(t_lmt_list *list,
				t_lmt_list_free_content free_content);

///	- method
int			lmt_list_append(t_lmt_list *list, void *content);
int			lmt_list_iterate_for_each(t_lmt_list *dummy,
				t_lmt_iterator_for_each function);
int			lmt_list_iterate_for_each_enumerated(t_lmt_list *dummy,
				t_lmt_iterator_for_each_enumerated function);

#endif
