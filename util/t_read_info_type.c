/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_read_info_m.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:58:18 by jeonpark          #+#    #+#             */
/*   Updated: 2021/06/13 13:30:23 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_read_info.h"
#include "util.h"

t_read_info	*alloc_read_info(void)
{
	t_read_info	*p_info;

	p_info = lmt_alloc(sizeof(t_read_info));
	return (p_info);
}

void		init_read_info(t_read_info *p_info, int fd)
{
	p_info->fd = fd;
	p_info->reads_len = 0;
	p_info->p_cursor = p_info->buffer;
	p_info->p_line = NULL;
}

t_read_info	*new_read_info(int fd)
{
	t_read_info	*p_info;

	p_info = alloc_read_info();
	init_read_info(p_info, fd);
	return (p_info);
}

void		free_read_info(t_read_info *p_info)
{
	free(p_info->p_line);
	free(p_info);
}
