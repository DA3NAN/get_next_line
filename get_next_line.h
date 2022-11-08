/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:34:25 by aait-mal          #+#    #+#             */
/*   Updated: 2022/11/07 19:01:19 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>
// Temp
# include<stdio.h>
//

typedef struct s_list
{
	char			content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
char	*line(int fd);

#endif
