/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:58:18 by jeonpark          #+#    #+#             */
/*   Updated: 2021/06/14 23:06:41 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ALLOCATION_ERROR		1
# define READ_ERROR				2
# define WRITE_ERROR			3

void	lmt_exit(int exit_code, char *string);

#endif
