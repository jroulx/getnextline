#include "get_next_line.h"

int			ft_checkerror(char **line, char **str)
{
	if (line == NULL)
		return (-1);
	if (!*str)
	{
		if (!(*str = ft_strnew(BUFF_SIZE + 1))) //MALLOC ICI
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
	if (!(*tmp = ft_strnew(k))) // MALLOC ICI
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
	char *tmp2;

	while (test_str(*str) == -1)
	{
		if(!(k = read(fd, buffer, BUFF_SIZE)))
			return (0);
		buffer[k] = '\0';
		*str = ft_strdup((const char*)buffer); //MALLOC
		if(tmp_init(&tmp, *str) != -2)
		{
			tmp2 = *line;
			if(!(*line = ft_strjoin(*line, tmp))) //MALLOC
				return (0);
			free(tmp);
			free(tmp2);
		}
	}
	*str += test_str(*str) + 1;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char *str;
	char		*tmp;
	char		*tmp2;

	if (ft_checkerror(line, &str) == -1) //MALLOC checkerror
		return (-1);
	*line = ft_strnew(0); // MALLOC ?
	if (str[0] == '\n')
	{
			*line = ft_strdup(""); // MALLOC ?
			str++;
			return(1);
	}
	if (str[0])
	{
		tmp2 = *line;
		tmp_init(&tmp, str); //MALLOC TMP
		*line = ft_strjoin(*line, tmp); // MALLOC RETURN SUR LINE
		while (str[0] != '\n' && str[0] != '\0')
			str++;
		free(tmp);
		free(tmp2);
	}
	if (ft_reader (&str, line, fd))
		return (1);
	else return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	char	*line;

	line = NULL;
	fd = 0;
	fd2 = 0;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
			ft_putendl(line);
			ft_putendl("-----");
			free(line);
		}
		close(fd);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
			ft_putendl(line);
			ft_putendl("-----");
			free(line);
			if (get_next_line(fd2, &line) == 1)
			{
				ft_putendl(line);
				ft_putendl("*****");
				free(line);
			}
		}
		close(fd);
		close(fd2);
	}
}