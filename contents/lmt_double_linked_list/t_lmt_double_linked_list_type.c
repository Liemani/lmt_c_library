/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_double_linked_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:54:35 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/14 14:36:04 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// free()
#include "t_lmt_double_linked_list.h"
#include "lmt_c_library.h"	// lmt_alloc()

static t_lmt_double_linked_list	*lmt_double_linked_list_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_double_linked_list)));
}

static void	lmt_double_linked_list_init(t_lmt_double_linked_list *list,
		void *content)
{
	list->content = content;
}

t_lmt_double_linked_list	*lmt_double_linked_list_new(void *content)
{
	t_lmt_double_linked_list	*list;

	list = lmt_double_linked_list_alloc();
	lmt_double_linked_list_init(list, content);
	return (list);
}

void	lmt_double_linked_list_free_element(
		t_lmt_double_linked_list *element, t_free_content *free_content)
{
	if (element == NULL)
		return ;
	if (free_content != NULL)
		free_content(element->content);
	free(element);
}

void	lmt_double_linked_list_free(
		t_lmt_double_linked_list *list, t_free_content *free_content)
{
	t_lmt_double_linked_list	*element;
	t_lmt_double_linked_list	*next_element;

	if (list == NULL)
		return ;
	element = list;
	next_element = element->next;
	while (next_element != NULL)
	{
		lmt_double_linked_list_free_element(element, free_content);
		element = next_element;
		next_element = element->next;
	}
	lmt_double_linked_list_free_element(element, free_content);
}
