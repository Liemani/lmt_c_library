/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_list_ask.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:55:03 by jeonpark          #+#    #+#             */
/*   Updated: 2021/11/23 11:48:51 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// NULL
#include "lmt_list.h"

int	lmt_list_is_dummy(t_lmt_list *element)
{
	return (element->content == NULL);
}
