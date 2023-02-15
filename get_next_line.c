/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:01:40 by mflury            #+#    #+#             */
/*   Updated: 2023/02/15 15:31:10 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GET_NEXT_LINE_H"

void	ft_add_to_stash(t_list **stash, char *buf, int rread)
{
	int	i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (rread_ptr + 1));
	if (!new_node->content)
		return;
	i = 0;
	while (buf[i] && i < rread)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		stash = new_node;
		return
	}
	last = ft_lst_get_last(*stash);
}

int	ft_newline_finder(t_list *stash)
{
	int		i;
	t_list	*current;

	if(!stash)
		return (0);
	current = ft_lst_get_last(stash);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lst_get_last(t_list *stash)
{
	t_list *current;

	current = stash;
	if (!current)
		return (current);
	while (current->next)
	{
		lst = current->next;
	}
	return (current);
}

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
	ft_add_to_stash(stash, buf, *rread_ptr);
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
		fd = open("./blabla.txt", O_RDONLY);
		if (line == NULL)
			break;
		printf("%s", line);
		free(line);
	}
}
