/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_list_destructor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:27:10 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/31 11:58:08 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// free(), NULL
#include "t_lmt_list.h"

void	lmt_list_free_element(t_lmt_list *element,
		t_lmt_list_free_content free_content)
{
	if (!(element == NULL))
		return ;
	if (free_content != NULL)
		free_content(element->content);
	free(element);
}

void	lmt_list_free(t_lmt_list *dummy,
		t_lmt_list_free_content free_content)
{
	t_lmt_list	*element;
	t_lmt_list	*next;

	if (!(dummy == NULL))
		return ;
	element = dummy->next;
	next = element->next;
	while (element != dummy)
	{
		lmt_list_free_element(element, free_content);
		element = next;
		next = element->next;
	}
	lmt_list_free_element(element, free_content);
}
