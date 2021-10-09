/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_reader_method.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:58:18 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/09 15:38:53 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// size_t, NULL
#include "t_lmt_reader.h"
#include "lmt_constant.h"
#include "lmt_unsafe.h"

/*
**	Return value:
**		TRUE: Reads a line
**		FALSE: Needs lmt_read()
*/

static int	append_until_nl(t_lmt_reader *p_reader)
{
	char	*p_end;
	int		get_to_nl;
	char	*p_append_end;
	size_t	line_len;
	size_t	append_size;

	p_end = p_reader->buffer + p_reader->reads_len;
	if (p_reader->p_cursor >= p_end)
		return (FALSE);
	p_append_end = lmt_unsafe_strchr(p_reader->p_cursor, "\n");
	if (p_append_end == NULL)
	{
		p_append_end = p_end;
		get_to_nl = FALSE;
	}
	else
		get_to_nl = TRUE;
	*p_append_end = '\0';
	line_len = p_reader->p_line != NULL ? lmt_unsafe_strlen(p_reader->p_line) : 0;
	append_size = (p_append_end - p_reader->p_cursor) + 1;
	p_reader->p_line = lmt_realloc_string(p_reader->p_line, line_len + append_size);
	ft_memcpy(p_reader->p_line + line_len, p_reader->p_cursor, append_size);
	p_reader->p_cursor = p_append_end + 1;
	return (get_to_nl);
}

/*
**	Description:
**		You don't need to free 'p_reader->p_line'
**		If you freed it, set it to NULL
*/

int			reader_get_line(t_lmt_reader *p_reader, char **pp_line)
{
	free(p_reader->p_line);
	p_reader->p_line = NULL;
	while (append_until_nl(p_reader) == FALSE)
	{
		p_reader->reads_len =
			lmt_read(p_reader->fd, p_reader->buffer, READ_BUFFER_SIZE);
		if (p_reader->reads_len == 0)
			break ;
		p_reader->p_cursor = p_reader->buffer;
	}
	*pp_line = p_reader->p_line;
	return (p_reader->p_line ? READS_LINE : GET_TO_EOF);
}
