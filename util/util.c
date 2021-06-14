/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:58:18 by jeonpark          #+#    #+#             */
/*   Updated: 2021/06/15 23:21:54 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include "util.h"
#include "lmt_exit.h"
#include "lmt_unsafe.h"

void	*lmt_alloc(size_t size)
{
	void	*p_address;

	p_address = malloc(size);
	if (p_address == NULL)
		lmt_exit(ALLOCATION_ERROR, "");
	return (p_address);
}

ssize_t	lmt_read(int fd, void *buffer, size_t size)
{
	ssize_t	reads_len;

	reads_len = read(fd, buffer, size);
	if (reads_len == -1)
		exit_with_error(READ_ERROR);
	return (reads_len);
}

void	lmt_put_ch(const char ch)
{
	ssize_t	result;

	result = write(1, &ch, 1);
	if (result == -1)
		lmt_exit(WRITE_ERROR, "");
}

ssize_t	lmt_write(const char *string)
{
	ssize_t	number_of_bytes_write;

	if (string == NULL)
		return (0);
	number_of_bytes_write = write(1, string, lmt_strlen(string));
	if (number_of_bytes_write == -1)
		lmt_exit(WRITE_ERROR, "");
	return (number_of_bytes_write);
}

char	*lmt_realloc_string(char *string, size_t size)
{
	char	*duplicated_string;
	size_t	length_of_string;
	size_t	size_to_copy;

	if (size == 0)
	{
		free(string);
		return (NULL);
	}
	duplicated_string = lmt_alloc(sizeof(char) * size);
	if (string == NULL)
	{
		*duplicated_string = '\0';
		return (duplicated_string);
	}
	length_of_string = lmt_strlen(string);
	size_to_copy = length_of_string <= size - 1 ? length_of_string : size - 1;
	lmt_memcpy(duplicated_string, string, size_to_copy);
	free(string);
	duplicated_string[size_to_copy] = '\0';
	return (duplicated_string);
}
