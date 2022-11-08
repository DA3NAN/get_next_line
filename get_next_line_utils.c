/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:34:28 by aait-mal          #+#    #+#             */
/*   Updated: 2022/11/07 20:40:07 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

static t_list	*ft_lstnew(char content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

static void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

static int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		count;

	temp = lst;
	count = 0;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

static char	*store_string(t_list *lst)
{
	char	*buff;
	int		i;
	t_list	*temp;

	buff = malloc((ft_lstsize(lst) + 1) * sizeof(char));
	temp = lst;
	i = 0;
	while (temp)
	{
		buff[i] = temp->content;
		temp = temp->next;
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

char	*line(int fd)
{
	char		buff[1];
	t_list		*result;
	t_list		*new;
	static char	*buff2;
	int			i;

	i = 0;
	result = NULL;
	while (i < BUFFER_SIZE)
	{
		read(fd, buff, 1);
		new = ft_lstnew(*buff);
		ft_lstadd_back(&result, new);
		if (*buff == '\n')
			buff2 = store_string(result);
		if (*buff == '\0')
		{
			printf("\nEOF\n");
			return (buff2);
		}
		i++;
	}
	if (i == BUFFER_SIZE)
		return (buff2);
	return (0);
}
