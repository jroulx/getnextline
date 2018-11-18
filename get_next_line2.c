#include "get_next_line.h"

int			ft_checkerror(char **line, char **str)
{
	if (line == NULL)
		return (-1);
	if (!*str)
	{
		if (!(*str = (char *)malloc(sizeof (char) * BUFF_SIZE + 1)))
			return (-1)
	}
	return (0);
}

int			test_str(char *str)
{
	int k; // renvoie k si str contient des \n, sinon -1

	k = 0;
	if (!str)
		return (-1);
	while (str[k])
	{
		if (str[k] == '\n')
			return (k);
	}
	return (-1);
}

int			tmp_init(char **tmp, char *str, int rd_byte)
{
	int k;
	int y;

	k = 0;
	while (str[k] && str[k] != '\n')
		k++;
	if (k == 0)
		return (-1);
	if (!(*tmp =(char *)malloc(sizeof(char) * k + 1)))
		return (-1);
	y = 0;
	while (y < k)
	{
		(*tmp)[y] = str[y];
		y++;
	}
	(*tmp)[y] = '\0';
	return (1);
}

int 		ft_reader(char **str, char **line, int fd)
{
	int k;
	char buffer[BUFF_SIZE + 1];
	char *tmp;

	while (test_str(*str) == -1)
	{
		buffer[k] = '\0';
		k = read(fd, buffer, BUFF_SIZE);
		ft_strcpy(*str, (char const*)buffer);
		free (tmp);
		tmp_init(&tmp, *str, k);
		*line = ft_strjoin(*line, tmp);	
	}
	*str += test_str(*str) + 1;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char *str;

	if (ft_checkerror(line, str) == -1)
		return (-1);

	if (str[0] == '\n')
		{
			*line = ft_strdup("");
			str++;
			return(1);
		}
	if (str[0])
	{
		ft_strjoin(*line, str);
		while (str[0])
			str++;
	}
	if (ft_reader (&str, line, fd))
		return (1);
}