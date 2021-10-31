/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:38:40 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/31 10:34:39 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>	// ssize_t
#include <stddef.h>	// NULL
#include <unistd.h>	// write()
#include "lmt_io.h"
#include "lmt_primitive_type.h"	// lmt_str_count()

ssize_t	lmt_write(int fd, const char *string)
{
	if (!(string != NULL))
		return (0);
	return (write(fd, string, lmt_str_count(string)));
}
