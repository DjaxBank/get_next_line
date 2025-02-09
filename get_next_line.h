/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbank <dbank@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:32:31 by dbank             #+#    #+#             */
/*   Updated: 2024/11/13 15:20:10 by dbank            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

char	*get_next_line(int fd);
char	*alloc_new(char *oldstring, int extra, char *buf, size_t *bufpos);
char	*copy_new(char *strings[2], size_t end, size_t i, size_t *j);
size_t	find_limit(char *buf, size_t i, bool *has_newline);
size_t	has_nl(char *line);
char	*error_return(size_t *bufpos, int *b_read, char *buf, char *line);
int		file_done(int b_read, char *line);

#endif