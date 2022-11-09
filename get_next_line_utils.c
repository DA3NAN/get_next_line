/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:34:28 by aait-mal          #+#    #+#             */
/*   Updated: 2022/11/08 19:20:51 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*fill(char *p, const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (*s1)
	{
		p[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		p[i] = *s2;
		s2++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size;
	char	*string;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = malloc(size * sizeof(char));
	if (!string)
		return (0);
	string = fill(string, s1, s2);
	free(s1);
	return (string);
}

char	*get_line(char *string)
{
	char	*line;
	int		i;

	if (!string)
		return (NULL);
	i = 0;
	while (string[i] != '\n' && string[i])
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (string[i] != '\n' && string[i])
	{
		line[i] = string[i];
		i++;
	}
	if (string[i] == '\n')
	{
		line[i] = string[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_left_string(char	*string)
{
	char	*new_string;
	int		i;
	int		j;

	i = 0;
	while (string[i] != '\n' && string[i])
		i++;
	if (!string)
	{
		free(string);
		return (NULL);
	}
	new_string = malloc((ft_strlen(string) - i + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	j = 0;
	while (string[i])
		new_string[j++] = string[i++];
	new_string[j] = '\0';
	free(string);
	return (new_string);
}