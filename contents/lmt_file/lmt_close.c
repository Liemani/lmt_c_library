/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:33:30 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/30 14:45:03 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// lmt_close()
#include <stdlib.h>	// exit()
#include "lmt_file.h"

void	lmt_close(int fd)
{
	if (close(fd) == -1)
		exit(0);
}
