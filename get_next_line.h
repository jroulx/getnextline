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
void	*ft_memcpy(void *dest, const void *src, size_t howmany);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcpy(char *dest, const char *src);
int 	ft_strlen(const char *str);
void	ft_putchar(char c);
void 	ft_putstr(char *str);
char	*ft_strjoin(char const *s1, char const *s2);

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
	while (s2[k] && s2[k])
	{
		join[y] = s2[k];
		k++;
		y++;
	}
	join[y] = '\0';
	return (join);
}

#endif