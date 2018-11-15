/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulx <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:32:59 by jroulx            #+#    #+#             */
/*   Updated: 2018/11/15 13:34:08 by jroulx           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char	buffer[BUFF_SIZE + 1];
	char	*str;
	char	*free_M;
	int		k;

	buffer[0] = 's';
	*line = (char *)malloc(sizeof (char) * BUFF_SIZE + 1);
	while(buffer[0] != '\n' && (k = read(fd, buffer, BUFF_SIZE)))
	{
		free_M = str;
		str = (char *)malloc(sizeof (char) * BUFF_SIZE);
		free(free_M);
		free_M = *line;
		*line = ft_strjoin(*line, str);
		free(free_M);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int k;
	int fd;
	char **line;

	if((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	get_next_line(fd, line);
	close(fd);
	k = 0;
	while (*line[k])
	return (0);
}

