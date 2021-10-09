/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:33:31 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/09 15:34:29 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>	// open()
#include <stdlib.h>	// exit()
#include "lmt_fcntl.h"

int	lmt_open(const char *path, int oflag, mode_t mode)
{
	int	fd;
	fd = open(path, oflag, mode);
	if (fd == -1)
		exit(1);
	return (fd);
}
