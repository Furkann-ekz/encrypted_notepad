#include "library.h"

int	ft_strcmp(char *s1, char *s2)
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

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s3;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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

char	*ft_get_read(int fd, char *str)
{
	char	*temp;
	int		rd;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
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
