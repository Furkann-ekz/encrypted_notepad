#include "library.h"

unsigned char	*ft_encryption(unsigned char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] < 70)
			str[i] += 11;
		else if (str[i] >= 70 && str[i] < 108)
			str[i] -= 7;
		else if (str[i] >= 108 && str[i] < 146)
			str[i] += 13;
		else if (str[i] >= 146 && str[i] < 184)
			str[i] -= 5;
		else if (str[i] >= 184 && str[i] < 222)
			str[i] += 17;
		else if (str[i] >= 222 && str[i] <= 255)
			str[i] -= 3;
		i++;
	}
	return (str);
}

unsigned char	*ft_decryption(unsigned char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] - 11 >= 32 && str[i] - 11 < 70)
			str[i] -= 11;
		else if (str[i] + 7 >= 70 && str[i] + 7 < 108)
			str[i] += 7;
		else if (str[i] - 13 >= 108 && str[i] - 13 < 146)
			str[i] -= 13;
		else if (str[i] + 5 >= 146 && str[i] + 5 < 184)
			str[i] += 5;
		else if (str[i] - 17 >= 184 && str[i] - 17 < 222)
			str[i] -= 17;
		else if (str[i] + 3 >= 222 && str[i] + 3 <= 255)
			str[i] += 3;
		i++;
	}
	return (str);
}

/*
		if (str[i] >= 31 && str[i] < 40)
			str[i] = ft_bcryptor(str[i]);
		else if (str[i] >= 41 && str[i] < 49)
			str[i] = ft_bcryptor(str[i]);
		else if (str[i] >= 50 && str[i] < 59)
			str[i] = ft_bcryptor(str[i]);
		else if (str[i] >= 60 && str[i] < )
			str[i] = ft_bcryptor(str[i]);
		else if (str[i] >= 50 && str[i] < 65)
			str[i] = ft_dcrpytor(str[i]);
		else if (str[i] >= 65 && str[i] < 80)
			str[i] = ft_dcrpytor(str[i]);
		else if (str[i] >= 80 && str[i] < 95)
			str[i] = ft_dcrpytor(str[i]);
		else if (str[i] >= 95 && str[i] < 110)
			str[i] = ft_tcrpytor(str[i]);
		else if (str[i] >= 110 && str[i] < 128)
			str[i] = ft_tcrpytor(str[i]);

char	g_character;
int				g_i;

char	ft_bcryptor(char c)
{
	g_i = 0;
	g_character = 0;
	while (g_i < 7)
	{
		if ((c >> g_i) & 1)
			g_character += 0;
		else
			g_character += 1;
		g_i++;
	}
	return (g_character);
}

char	ft_dcrpytor(char c)
{
	g_i = 0;
	g_character = 0;
	while (g_i < 4)
	{
		if ((c >> g_i) & 1)
			g_character += 0;
		else
			g_character += 1;
		g_i++;
	}
	while (g_i >= 4 && g_i < 7)
	{
		if ((c >> g_i) & 1)
			g_character += 1;
		else
			g_character += 0;
		g_i++;
	}
	return (g_character);
}

char	ft_tcryptor(char c)
{
	g_i = 0;
	g_character = 0;
	while (g_i < 7)
	{
		if ((c >> g_i) & 1)
			g_character += 0;
		else
			g_character += 1;
		g_i++;
	}
	return (g_character);
}
*/
