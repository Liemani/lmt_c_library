/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_list_constructor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:26:57 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/31 11:51:12 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// NULL
#include "t_lmt_list.h"
#include "t_lmt_list_static.h"

t_lmt_list	*lmt_list_new(void)
{
	t_lmt_list	*dummy;

	dummy = lmt_list_new_static(NULL);
	if (dummy == NULL)
		return (NULL);
	dummy->prev = dummy;
	dummy->next = dummy;
	return (dummy);
}
