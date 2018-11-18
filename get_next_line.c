#include "get_next_line.h"

int			ft_checkerror(char **line, char **str)
{
	if (line == NULL)
		return (-1);
	if (!*str)
	{
		if (!(*str = ft_strnew(BUFF_SIZE + 1)))
			return (-1);
	}
	return (0);
}

int			test_str(char *str)
{
	int k; // renvoie k si str contient des \n, sinon -1

	k = 0;
	if (!str)
		return (-2);
	while (str[k])
	{
		if (str[k] == '\n')
			return (k);
		k++;
	}
	return (-1);
}

int			tmp_init(char **tmp, char *str)
{
	int k;
	int y;

	k = 0;
	while (str[k] && str[k] != '\n')
		k++;
	if (k == 0)
		return (-2);
	if (!(*tmp =ft_strnew(k)))
		return (-1);
	y = 0;
	while (y < k)
	{
		(*tmp)[y] = str[y];
		y++;
	}
	(*tmp)[k] = '\0';
	return (1);
}

int 		ft_reader(char **str, char **line, int fd)
{
	int k;
	char buffer[BUFF_SIZE + 1];
	char *tmp;

	while (test_str(*str) == -1)
	{
		if(!(k = read(fd, buffer, BUFF_SIZE)))
			return (0);
		buffer[k] = '\0';
		*str = ft_strdup((const char*)buffer);
		if(tmp_init(&tmp, *str) != -2)
		{
			if(!(*line = ft_strjoin(*line, tmp)))
				return (0);
			free(tmp);
		}
	}
	*str += test_str(*str) + 1;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char *str;
	char		*tmp;

	if (ft_checkerror(line, &str) == -1)
		return (-1);
	*line = ft_strnew(0);
	if (str[0] == '\n')
	{
			*line = ft_strdup("");
			str++;
			return(1);
	}
	if (str[0])
	{
		tmp_init(&tmp, str);
		*line = ft_strjoin(*line, tmp);
		while (str[0] != '\n' && str[0] != '\0')
			str++;
		free(tmp);
	}
	if (ft_reader (&str, line, fd))
		return (1);
	else return (0);
}

int main(int argc, char **argv)
{
	char *line;
	int 	fd;
	int 	k;

	k = 1;
	(void)argc;
	if((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	while (k == 1)
	{
		k = get_next_line(fd, &line);
		ft_putchar('\n');
		ft_putstr(line);
	}
	ft_putchar('\n');
	free(line);
	close (fd);
	return (0);
}