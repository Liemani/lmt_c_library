/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_unsafe.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:22:05 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/19 14:13:12 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_UNSAFE_H
# define LMT_UNSAFE_H

# include <stddef.h>

size_t	lmt_unsafe_strlen(const char *string);
void	*lmt_unsafe_memcpy(void *p_write, const void *p_read, size_t size);
void	*lmt_unsafe_strdup(const char *string);

#endif
