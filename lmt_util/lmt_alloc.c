/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:09:47 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/01 14:54:37 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lmt_util.h"

void	*lmt_alloc(size_t size)
{
	void	*p_address;

	p_address = malloc(size);
	if (p_address == NULL)
		lmt_exit(ALLOCATION_ERROR, "");
	return (p_address);
}