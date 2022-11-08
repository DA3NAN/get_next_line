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

char	*ft_strchr(char *s, int c)
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

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = malloc(size * sizeof(char));
	if (!string)
		return (0);
	string = fill(string, s1, s2);
	return (string);
}
