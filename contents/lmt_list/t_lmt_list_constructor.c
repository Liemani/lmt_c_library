/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_list_constructor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:26:57 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/28 13:33:56 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_list.h"
#include "t_lmt_list_inner.h"
#include "lmt_c_library.h"	// lmt_alloc()

static t_lmt_list	*lmt_list_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_list)));
}

static void	lmt_list_init(t_lmt_list *list, void *content)
{
	list->content = content;
}

t_lmt_list	*lmt_list_new_core(void *content)
{
	t_lmt_list	*list;

	if (content == NULL)
		return (NULL);
	list = lmt_list_alloc();
	lmt_list_init(list, content);
	return (list);
}

t_lmt_list	*lmt_list_new(void)
{
	t_lmt_list	*dummy;

	dummy = lmt_list_alloc();
	lmt_list_init(dummy, NULL);
	dummy->prev = dummy;
	dummy->next = dummy;
	return (dummy);
}
