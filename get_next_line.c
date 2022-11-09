/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:34:30 by aait-mal          #+#    #+#             */
/*   Updated: 2022/11/08 19:21:44 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

static char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (*s == (char)c)
		return (s);
	return (0);
}


static char	*get_whole_string(int fd, char *string)
{
	char	*buff;
	size_t	bytes_read;

	bytes_read = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!ft_strchr(string, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		buff[bytes_read] = '\0';
		string = ft_strjoin(string, buff);
	}
	free(buff);
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*line;

	string = get_whole_string(fd, string);
	if (!string)
		return (0);
	line = get_line(string);
	string = get_left_string(string);
	return (line);
}
