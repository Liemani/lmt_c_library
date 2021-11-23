/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_list_static_constructor.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:05:28 by jeonpark          #+#    #+#             */
/*   Updated: 2021/11/23 11:48:32 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// malloc()
#include "lmt_list_static.h"
#include "lmt_list.h"

static t_lmt_list	*lmt_list_alloc(void)
{
	return (malloc(sizeof(t_lmt_list)));
}

static void	lmt_list_init(t_lmt_list *list, void *content)
{
	list->content = content;
}

t_lmt_list	*lmt_list_new_static(void *content)
{
	t_lmt_list	*list;

	list = lmt_list_alloc();
	if (list == NULL)
		return (NULL);
	lmt_list_init(list, content);
	return (list);
}
