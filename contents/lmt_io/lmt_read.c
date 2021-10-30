/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:32:40 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/30 14:45:39 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// read()
#include <sys/types.h>	// ssize_t
#include <stdlib.h>	// exit(), size_t
#include "lmt_io.h"

ssize_t	lmt_read(int fd, void *buffer, size_t size)
{
	ssize_t	count_reads;

	if (!(buffer != NULL))
		return (0);
	count_reads = read(fd, buffer, size);
	if (count_reads == -1)
		exit(0);
	return (count_reads);
}
