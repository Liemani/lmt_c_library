/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_put_ch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:38:42 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/01 14:54:37 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include "lmt_util.h"

void	lmt_put_ch(const char ch)
{
	ssize_t	result;

	result = write(1, &ch, 1);
	if (result == -1)
		lmt_exit(WRITE_ERROR, "");
}
