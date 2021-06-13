/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_read_info.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:58:18 by jeonpark          #+#    #+#             */
/*   Updated: 2021/06/13 16:41:00 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_READ_INFO_H
# define T_READ_INFO_H

# include <sys/types.h>

# define READ_BUFFER_SIZE	512

# define GET_TO_EOF			0
# define READS_LINE			1

typedef struct	s_read_info
{
	int			fd;
	char		buffer[READ_BUFFER_SIZE + 1];
	ssize_t		reads_len;
	char		*p_cursor;
	char		*p_line;
}				t_read_info;

t_read_info		*alloc_read_info(void);
void			init_read_info(t_read_info *p_info, int fd);
t_read_info		*new_read_info(int fd);
void			free_read_info(t_read_info *p_info);
int				read_info_get_line(t_read_info *p_read_info, char **pp_line);

#endif
