/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_is_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:58:44 by jeonpark          #+#    #+#             */
/*   Updated: 2021/06/14 21:59:22 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	lmt_isdigit(const char ch)
{
	return ('0' <= ch && ch <= '9');
}
