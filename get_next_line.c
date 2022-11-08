/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:34:30 by aait-mal          #+#    #+#             */
/*   Updated: 2022/11/08 16:19:08 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

static int	newline_included(char *str, int	*newline_index)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			*newline_index = i;
			return (1);
		}
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*buff;
	int			bytes_read;
	int			newline_index;
	static int	i = 0;

	if (!temp)
		temp = "";
	bytes_read = 1;
	newline_index = 0;
	buff = calloc(BUFFER_SIZE + 1, sizeof(char));
	if (i == 1)
		return (NULL);
	while (!newline_included(temp, &newline_index) && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		temp = ft_strjoin(temp, buff);
	}
	buff = ft_substr(temp, 0, newline_index + 1);
	temp = ft_substr(temp, newline_index + 1, ft_strlen(temp) - newline_index);
	if (!newline_included(temp, &newline_index) && bytes_read == 0)
		i = 1;
	return (buff);
}
