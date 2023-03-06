/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:01:40 by mflury            #+#    #+#             */
/*   Updated: 2023/02/22 16:25:54 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// read(int fd, void *buf, size_t count);
//			fd from where we read.
// 					 buffer of the read.
//									size

char	ft_checkread(t_list *gnl)
{
	char	c;

	if (gnl->pos >= gnl->maxsize)
	{
		gnl->pos = 0;
		gnl->maxsize = read(gnl->fd, gnl->content, BUFFER_SIZE);
		if (gnl->maxsize <= 0)
			return (0);
	}
	c = gnl->content[gnl->pos];
		gnl->pos++;
	return (c);
}

//initialise the struct content.

int	ft_init(t_list *gnl, int fd)
{
	gnl->fd = fd;
	gnl->pos = 0;
	gnl->maxsize = read(gnl->fd, gnl->content, BUFFER_SIZE);
	if (gnl->maxsize <= 0)
		return (0);
	return (1);
}

// create a static struct (t_list gnl) and set its fd to -1 (not set yet),
// set the fd of the struct (on the first time) with ft_init,
// 

char	*get_next_line(int fd)
{
	static t_list	gnl = {.fd = -1};
	char			c;
	char			*line;

	line = NULL;
	if (gnl.fd != fd)
	{
		if (ft_init(&gnl, fd) != 1)
			return (NULL);
	}
	c = ft_checkread(&gnl);
	while (c)
	{
		line = ft_strjoin(line, c);
		if (c == '\n')
			return (line);
		c = ft_checkread(&gnl);
	}
	return (line);
}
