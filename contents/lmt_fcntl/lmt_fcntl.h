/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_fcntl.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:33:29 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/09 15:35:30 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_FCNTL_H
# define LMT_FCNTL_H

# include <fcntl.h>	// mode_t

int		lmt_open(const char *path, int oflag, mode_t mode);
void	lmt_close(int fd);

#endif
