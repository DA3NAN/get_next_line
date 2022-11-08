/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:34:28 by aait-mal          #+#    #+#             */
/*   Updated: 2022/11/08 14:10:32 by aait-mal         ###   ########.fr       */
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

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	index;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	if (start > s_len)
		len = 0;
	substring = malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	index = 0;
	while (index < len && start <= s_len)
	{
		substring[index] = s[start];
		start++;
		index++;
	}
	substring[index] = '\0';
	return (substring);
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

char	*ft_strjoin(const char *s1, const char *s2)
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
