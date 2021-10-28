/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:54:33 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/28 13:32:45 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_list_H
# define T_LMT_list_H

#include "t_lmt_iterator.h"	// protocol

typedef void	(*t_lmt_list_free_content)(void *content);

///	- description: circular double linked list
///	- content: non-optional except dummy
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
void		lmt_list_append(t_lmt_list *list, void *content);
void		lmt_list_iterate_for_each(t_lmt_list *dummy,
				t_lmt_iterator_for_each function);

#endif
