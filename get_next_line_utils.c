/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:01:51 by mflury            #+#    #+#             */
/*   Updated: 2023/02/15 17:15:57 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char c)
{
	int		i;
	int		lenstr;
	char	*newstr;

	lenstr = ft_strlen(str);
	i = 0;
	newstr = malloc(lenstr + 2);
	if (!newstr)
		return (NULL);
	while (i < lenstr)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i++] = c;
	newstr[i] = '\0';
	if (str)
		free(str);
	return (newstr);
}
