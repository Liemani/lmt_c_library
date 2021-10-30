/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:58:18 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/30 14:45:13 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_IO_H
# define LMT_IO_H

# include <stddef.h>	// size_t
# include <sys/types.h>	// ssize_t

ssize_t	lmt_read(int fd, void *buffer, size_t size);
ssize_t	lmt_write(int fd, const char *string);

#endif
