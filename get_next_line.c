/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:01:40 by mflury            #+#    #+#             */
/*   Updated: 2023/02/13 11:58:34 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GET_NEXT_LINE_H"

char	ft_read_and_stash(fd, t_list **stash, int *rread_ptr)
{
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buf)
		return;
	rread_ptr = (int)read(fd, buf, BUFFER_SIZE);
	if((*stash == NULL && *rread_ptr == 0) || *rread_ptr == -1)
	{
		free(buf);
		return;
	}
	buf[*rread_ptr] = '\0';
}

char	*ft_get_next_line(int fd)
{
	static t_list	*stash;
	char			*line;
	int				rread;

	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return(NULL);
	stash = NULL;
	line = NULL;
	rread = 1;
	ft_read_and_stash(fd, &stash, &rread);
	if(stash == NULL)
		return(NULL);

	return(line);
}


int	main()
{
	int		fd;
	char	*line;

	While(1)
	{
		fd = open(blabla.txt, O_RDONLY);
		if (line == NULL)
			break;
		printf("%s", line);
		free(line);
	}
}
