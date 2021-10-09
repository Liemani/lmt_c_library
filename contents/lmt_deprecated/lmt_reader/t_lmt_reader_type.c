/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_reader_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:58:18 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/09 15:36:52 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// free(), NULL
#include "t_lmt_reader.h"
#include "lmt_alloc.h"

static	t_lmt_reader	*reader_alloc(void)
{
	t_lmt_reader	*p_reader;

	p_reader = lmt_alloc(sizeof(t_lmt_reader));
	return (p_reader);
}

static	void		reader_init(t_lmt_reader *p_reader, int fd)
{
	p_reader->fd = fd;
	p_reader->reads_len = 0;
	p_reader->p_cursor = p_reader->buffer;
	p_reader->p_line = NULL;
}

t_lmt_reader	*reader_new(int fd)
{
	t_lmt_reader	*p_reader;

	p_reader = reader_alloc();
	reader_init(p_reader, fd);
	return (p_reader);
}

void		reader_free(t_lmt_reader *p_reader)
{
	free(p_reader->p_line);
	free(p_reader);
}
