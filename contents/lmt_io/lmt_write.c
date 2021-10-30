/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:38:40 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/30 14:47:16 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// write()
#include <sys/types.h>	// ssize_t
#include <stdlib.h>	// exit()
#include "lmt_io.h"
#include "lmt_primitive_type.h"	// lmt_str_count()

ssize_t	lmt_write(int fd, const char *string)
{
	ssize_t	count_writes;

	if (!(string != NULL))
		return (0);
	count_writes = write(fd, string, lmt_str_count(string));
	if (count_writes == -1)
		exit(0);
	return (count_writes);
}
