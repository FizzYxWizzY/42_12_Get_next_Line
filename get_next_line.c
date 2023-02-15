/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:01:40 by mflury            #+#    #+#             */
/*   Updated: 2023/02/15 17:10:33 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	checkread(t_list *gnl)
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

int	init(t_list *gnl, int fd)
{
	gnl->fd = fd;
	gnl->pos = 0;
	gnl->maxsize = read(gnl->fd, gnl->content, BUFFER_SIZE);
	if (gnl->maxsize <= 0)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list	gnl = {.fd = -1};
	char			c;
	char			*line;

	line = NULL;
	if (gnl.fd != fd)
	{
		if (init(&gnl, fd) != 1)
			return (NULL);
	}
	c = checkread(&gnl);
	while (c)
	{
		line = ft_strjoin(line, c);
		if (c == '\n')
			return (line);
		c = checkread(&gnl);
	}
	return (line);
}
/*
int	main()
{
	int		fd;
	char	*line;

	While(1)
	{
		fd = open("./blabla.txt", O_RDONLY);
		if (line == NULL)
			break;
		printf("%s", line);
		free(line);
	}
}
*/
