/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:38:40 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 13:49:08 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "lmt_io.h"
#include "lmt_primitive_type.h"

ssize_t	lmt_write(const char *string)
{
	ssize_t	number_of_bytes_write;

	if (string == NULL)
		return (0);
	number_of_bytes_write = write(1, string, lmt_str_count(string));
	if (number_of_bytes_write == -1)
		exit(1);
	return (number_of_bytes_write);
}