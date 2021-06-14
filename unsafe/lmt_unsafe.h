/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_unsafe.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:22:05 by jeonpark          #+#    #+#             */
/*   Updated: 2021/06/14 22:30:26 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_UNSAFE_H
# define LMT_UNSAFE_H

# include <stdlib.h>

size_t	lmt_strlen(const char *string);
void	*lmt_memcpy(void *p_write, const void *p_read, size_t size);

#endif
