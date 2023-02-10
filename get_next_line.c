/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:01:40 by mflury            #+#    #+#             */
/*   Updated: 2023/02/10 16:52:55 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GET_NEXT_LINE_H"

char	ft_manage_buffer(fd, *buf, count)
{

}

char	*ft_get_next_line(int fd)
{
	static t_list	*stash;
	char			*line;
	int				rread;

	stash = NULL;
	line = 0;
	read = 0;

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
