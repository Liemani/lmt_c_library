/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:58:18 by jeonpark          #+#    #+#             */
/*   Updated: 2021/06/14 23:15:45 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "lmt_exit.h"
#include "lmt_unsafe.h"

void	lmt_exit(int exit_code, char *string)
{
	if (string != NULL)
		write(2, string, lmt_strlen(string));
	exit(exit_code);
}
