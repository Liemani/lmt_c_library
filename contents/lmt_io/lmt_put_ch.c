/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_put_ch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:38:42 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/28 15:55:47 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>	// ssize_t
#include <unistd.h>	// write()
#include <stdlib.h>	// exit()
#include "lmt_io.h"

void	lmt_put_ch(const char ch)
{
	ssize_t	return_value;

	return_value = write(1, &ch, 1);
	if (return_value == -1)
		exit(0);
}
