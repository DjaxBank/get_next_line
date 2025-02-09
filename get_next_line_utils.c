/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbank <dbank@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:01:52 by dbank             #+#    #+#             */
/*   Updated: 2024/11/13 15:17:06 by dbank            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	find_limit(char *buf, size_t i, bool *has_newline)
{
	size_t	bufpos;

	bufpos = i;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
		{
			*has_newline = true;
			return (i - bufpos + 1);
		}
		i++;
	}
	return (i - bufpos);
}

char	*error_return(size_t *bufpos, int *b_read, char *buf, char *line)
{
	size_t	i;

	if (*b_read <= 0)
	{
		i = 0;
		*bufpos = 0;
		*b_read = 0;
		while (i < BUFFER_SIZE + 1)
		{
			buf[i] = '\0';
			i++;
		}
	}
	free(line);
	return (NULL);
}

int	file_done(int b_read, char *line)
{
	if (line != NULL)
		if (b_read == 0 && line[0] != '\0')
			return (1);
	return (0);
}
