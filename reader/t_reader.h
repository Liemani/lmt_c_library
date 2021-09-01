/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_reader.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:58:18 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/16 13:22:17 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_READER_H
# define T_READER_H

# include <sys/types.h>

# define READ_BUFFER_SIZE	512

# define GET_TO_EOF			0
# define READS_LINE			1

typedef struct	s_reader
{
	int			fd;
	char		buffer[READ_BUFFER_SIZE + 1];
	ssize_t		reads_len;
	char		*p_cursor;
	char		*p_line;
}				t_reader;

t_reader		*reader_new(int fd);
void			reader_free(t_reader *p_reader);

int				reader_get_line(t_reader *p_reader, char **pp_line);

#endif
