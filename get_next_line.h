#ifndef HEADER_H
# define HEADER_H

# define BUFF_SIZE 42

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
/*Alloue (avec malloc(3)) et retourne une chaine de caractères
/ “fraiche” terminée par un ’\0’ résultant de la concaténation
/ de s1 et s2. Si l’allocation echoue, la fonction renvoie NULL. */
void	*ft_memcpy(void *dest, const void *src, size_t howmany);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcpy(char *dest, const char *src);
int 	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dest, const void *src, size_t howmany);
void	ft_putnbr_fd(int nbr, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strnew(size_t size);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putstr(char const *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putendl(char const *s);
void	ft_strdel(char **as);
int		get_next_line(const int fd, char **line);
char	*ft_strchr(const char *s, int c);

char	*ft_strchr(const char *s, int c)
{
	int k;

	k = 0;
	while (s[k] != (char)c && (s[k]))
		k++;
	if (s[k] == (char)c)
		return ((char *)s + k);
	return (NULL);
}

void	ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
	return ;
}

void	ft_putendl(char const *s)
{
	ft_putendl_fd(s, 1);
}

void	ft_putendl_fd(char const *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr(char const *str)
{
	int k;

	k = 0;
	if (!str)
		return ;
	while (str[k])
	{
		ft_putchar(str[k]);
		k++;
	}
}

void	ft_putstr_fd(char const *s, int fd)
{
	int		k;

	if (!s)
		return ;
	k = 0;
	while (s[k])
	{
		ft_putchar_fd(s[k], fd);
		k++;
	}
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	k;

	k = 0;
	if (!s)
		return (NULL);
	if (!(sub = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (k < len)
	{
		sub[k] = s[k + start];
		k++;
	}
	sub[k] = '\0';
	return (sub);
}

char	*ft_strnew(size_t size)
{
	char		*newstr;
	char		*reset;
	size_t		k;

	k = 0;
	if (!(newstr = (char *)malloc((sizeof(char)) * size + 1)))
		return (NULL);
	reset = newstr;
	while (k <= size)
	{
		newstr[k] = '\0';
		k++;
	}
	return (reset);
}

void	ft_putnbr_fd(int nbr, int fd)
{
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr == -2147483648)
	{
		ft_putchar_fd('2', fd);
		nbr %= 1000000000;
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	else
		ft_putchar_fd(nbr + '0', fd);
}

void	*ft_memmove(void *dest, const void *src, size_t howmany)
{
	const char		*src2;
	char			*dest2;
	size_t		k;
	
	k = 0;
	src2 = src;
	dest2 = dest;
	if (src2 < dest2)
	{
		while (k < howmany)
		{
			dest2[howmany - 1] = src2[howmany - 1];
			howmany--;
		}
	}
	else
		while (k < howmany)
		{
			dest2[k] = src2[k];
			k++;
		}
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t howmany)
{
	size_t			k;
	unsigned char	*dest_temp;
	unsigned char	*src_temp;

	dest_temp = (unsigned char *)dest;
	src_temp = (unsigned char *)src;
	k = 0;
	while (k < howmany)
	{
		dest_temp[k] = src_temp[k];
		k++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*newstring;

	if (!(newstring = (char*)malloc((sizeof(char)) * ft_strlen(s) + 1)))
		return (NULL);
	ft_memcpy(newstring, s, ft_strlen(s));
	newstring[ft_strlen(s)] = (char)s[ft_strlen(s)]; 
	return (newstring);
}


char	*ft_strcpy(char *dest, const char *src)
{
	int k;

	k = 0;
	while (src[k])
	{
		dest[k] = src[k];
		k++;
	}
	dest[k] = '\0';
	return (dest);
}

int 	ft_strlen(const char *str)
{
	int k;

	k = 0;
	while (str[k])
		k++;
	return (k);
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
	if (!(join = ft_strnew(str_len + 1)))
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
		join[y] = s2[k++];
		y++;
	}
	join[y] = s2[k];
	return (join);
}
#endif