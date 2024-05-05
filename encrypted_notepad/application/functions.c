#include "library.h"

int	ft_strcmp(unsigned char *s1, unsigned char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}

size_t	ft_strlen(unsigned char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned char	*ft_strjoin(unsigned char *s1, unsigned char *s2)
{
	int		i;
	int		j;
	unsigned char	*s3;

	if (!s1)
	{
		s1 = (unsigned char *)malloc(1 * sizeof(unsigned char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s3 = (unsigned char *)malloc(sizeof(unsigned char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	i = -1;
	while (s1[++i] != 0)
		s3[i] = s1[i];
	j = -1;
	while (s2[++j] != 0)
	{
		s3[i + j] = s2[j];
	}
	s3[i + j] = '\0';
	free(s1);
	return (s3);
}

unsigned char	*ft_get_read(int fd, unsigned char *str)
{
	unsigned char	*temp;
	int				rd;

	temp = (unsigned char *)malloc(sizeof(unsigned char) * (BUFFER_SIZE + 1));
	rd = 1;
	if (!temp)
		return (NULL);
	while (rd > 0)
	{
		rd = read(fd, temp, BUFFER_SIZE);
		if (rd <= 0)
		{
			if (rd == 0)
				break ;
			free(temp);
			if (str)
				free(str);
			return (NULL);
		}
		temp[rd] = '\0';
		if (rd > 0)
			str = ft_strjoin(str, temp);
	}
	free(temp);
	return (str);
}
