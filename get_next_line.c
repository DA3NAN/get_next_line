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

static char	*get_hole_string(int fd, char *string)
{
	char	*buff;
	size_t	bytes_read;

	if (!string)
	{
		string = malloc(1 * sizeof(char));
		string[0] = '\0';
	}
	bytes_read = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (!ft_strchr(string, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		string = ft_strjoin(string, buff);
		buff[BUFFER_SIZE] = '\0';
	}
	free(buff);
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*string;

	string = get_hole_string(fd, string);
	printf("%s", string);
	return (0);
}
