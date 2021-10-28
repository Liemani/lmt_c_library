/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:38:40 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/28 15:58:20 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>	// ssize_t
#include <unistd.h>	// write()
#include <stdlib.h>	// exit()
#include "lmt_io.h"
#include "lmt_primitive_type.h"

ssize_t	lmt_write(int fd, const char *string)
{
	ssize_t	number_of_bytes_write;

	if (string == NULL)
		return (0);
	number_of_bytes_write = write(fd, string, lmt_str_count(string));
	if (number_of_bytes_write == -1)
		exit(0);
	return (number_of_bytes_write);
}
