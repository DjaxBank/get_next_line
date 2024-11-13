/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbank <dbank@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:31:53 by dbank             #+#    #+#             */
/*   Updated: 2024/11/13 15:19:51 by dbank            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static size_t	bufpos;
	char			*line;
	static int		b_read;
	bool			has_nl;
	static char		buf[BUFFER_SIZE + 1];

	line = malloc(1);
	if (line)
		line[0] = '\0';
	while (line != NULL)
	{
		has_nl = false;
		if ((int)bufpos >= b_read || buf[0] == '\0')
		{
			bufpos = 0;
			b_read = read(fd, buf, BUFFER_SIZE);
		}
		if (b_read < 0 || (b_read == 0 && line[0] == '\0'))
			break ;
		buf[b_read] = '\0';
		line = alloc_new(line, find_limit(buf, bufpos, &has_nl), buf, &bufpos);
		if (has_nl == true || (file_done(b_read, line)))
			return (line);
	}
	return (error_return(&bufpos, &b_read, buf, line));
}

char	*alloc_new(char *oldstring, int extra, char *buf, size_t *bufpos)
{
	char	*newstring;
	char	*strings[2];
	size_t	i;
	size_t	lenold;

	i = 0;
	lenold = 0;
	while (oldstring[lenold] != '\0')
		lenold++;
	newstring = malloc((lenold + extra + 1) * sizeof(char));
	while (i < lenold && newstring != NULL)
	{
		newstring[i] = oldstring[i];
		i++;
	}
	free(oldstring);
	if (newstring == NULL)
		return (NULL);
	strings[0] = newstring;
	strings[1] = buf;
	return (copy_new(strings, (lenold + extra), lenold, bufpos));
}

char	*copy_new(char *strings[2], size_t end, size_t i, size_t*j)
{
	while (i < end)
	{
		strings[0][i] = strings[1][*j];
		i++;
		(*j)++;
	}
	strings[0][i] = '\0';
	return (strings[0]);
}
