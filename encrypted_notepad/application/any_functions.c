#include "library.h"

void	list_starter(t_list *list)
{
	list->r_file = 0;
	list->w_file = 0;
	list->choose = 0;
	list->pss = 0;
	list->reader = NULL;
	list->reader_control = NULL;
	list->str = NULL;
	list->reader_control = (char *)calloc(1000, 1000);
	list->reader = (char *)calloc(1000, 1000);
	list->str = (char *)calloc(1000, 1000);
	if (!list->reader || !list->reader_control || !list->str)
	{
		printf("Bellek tahsisi yapılamadı... Program kapatılıyor\n");
		exit (1);
	}
}

int	ft_error(char *str, int choose)
{
	choose = 3;
	while ((choose != 0 && choose != 1 && choose != 2) || choose < 0)
	{
		system("clear");
		printf("Geçersiz giriş yaptınız. "
			"Lütfen sadece 0-1-2 değerleri arasından giriş yapınız.\n"
			"Notunuzu şifrelemek için 1,\n"
			"Şifrelediğiniz bir notu okumak için 2,\n"
			"Programı kapatmak için 0 girmeniz gerekmektedir: ");
		usleep(100);
		scanf (" %[^\n]", str);
		usleep(100);
		if ((str[0] == '0' || str[0] == '1' || str[0] == '2') && !str[1])
			choose = str[0] - 48;
	}
	return (choose);
}

void	ft_closer(t_list *list)
{
	if (list->r_file)
		close(list->r_file);
	if (list->w_file)
		close(list->w_file);
	if (list->pss)
		close(list->pss);
	free(list->reader);
	free(list->reader_control);
	free(list->str);
	free(list);
}

void	wrong_str(t_list *list)
{
	while ((ft_strcmp(list->str, (char *)"evet") != 0) && (ft_strcmp(list->str, (char *)"hayır") != 0))
	{
		system("clear");
		printf("Hatalı giriş yaptınız.\n"
			"Başka bir işlem yapmak istiyorsanız 'evet', istemiyorsanız 'hayır' yazınız: ");
		usleep(20);
		scanf (" %[^\n]", list->str);
		usleep(20);
	}
}

void	old_terminal(t_list *list)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &list->old);
}

void	new_terminal(t_list *list)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &list->new);
}

void	want_read(t_list *list)
{
	while (1)
	{
		if (ft_strcmp(list->str, (char *)"oku") == 0)
		{
			free(list->str);
			list->str = NULL;
			list->str = (char *)calloc(1000, 1000);
			list->str = ft_get_read(list->r_file, list->str);
			list->str = (char *)ft_decryption((unsigned char *)list->str);
			close (list->r_file);
			printf("%s\n", list->str);
			break ;
		}
		else
		{
			printf("Hatalı giriş yaptınız. Okumak için 'oku' yazınız: ");
			usleep(20);
			scanf (" %[^\n]", list->str);
			usleep(20);
		}
	}
}
