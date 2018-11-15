#ifndef HEADER_H
# define HEADER_H

# define BUFF_SIZE 1

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
/*Alloue (avec malloc(3)) et retourne une chaine de caractères
/ “fraiche” terminée par un ’\0’ résultant de la concaténation
/ de s1 et s2. Si l’allocation echoue, la fonction renvoie NULL. */
int 	ft_strlen(char *str)
{
	int k;

	k = 0;
	while (str[k])
		k++;
	return (k);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void 	ft_putstr(char *str)
{
	int k;

	k = 0;
	while (str[k])
	{
		ft_putchar(str[k]);
		k++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	str_len;
	int				k;
	int				y;
	char			*join;

	if (!s1 || !s2)
		return (NULL);
	str_len = ft_strlen(s1) + ft_strlen(s2);
	k = 0;
	if (!(join = (char *)malloc(sizeof (char) * str_len + 1)))
		return (NULL);
	while (s1[k])
	{
		join[k] = s1[k];
		k++;
	}
	y = k;
	k = 0;
	while (s2[k])
	{
		join[y] = s2[k];
		k++;
		y++;
	}
	join[y] = '\0';
	return (join);
}

#endif