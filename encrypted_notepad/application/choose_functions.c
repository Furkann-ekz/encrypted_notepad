#include "library.h"

int	ft_choose(t_list *list)
{
	list->choose = 3;
	printf("Lütfen yapmak istediğiniz işlemi seçiniz;\n"
		"Notunuzu şifrelemek için 1,\n"
		"Şifrelediğiniz bir notu okumak için 2,\n"
		"Programı kapatmak için 0 girmeniz gerekmektedir: ");
	usleep(20);
	scanf (" %[^\n]", list->str);
	usleep(20);
	if ((list->str[0] == '0' || list->str[0] == '1' || list->str[0] == '2') && !list->str[1])
		list->choose = list->str[0] - 48;
	if ((list->choose != 0 && list->choose != 1 && list->choose != 2) || list->choose < 0)
		list->choose = ft_error(list->str, list->choose);
	return (list->choose);
}

void	yes_or_no(t_list *list)
{
	while (1)
	{
		if (ft_strcmp(list->str, (char *)"evet") == 0)
		{
			system("clear");
			list->choose = ft_choose(list);
			break ;
		}
		else if (ft_strcmp(list->str, (char *)"hayır") == 0)
		{
			printf("\nNotlarınız güvende, programdan çıkılıyor... "
				"Sağlıklı kalın :)\n");
			ft_closer(list);
			sleep(1);
			system("clear");
			exit(0);
		}
		else
			wrong_str(list);
	}
}

void	ch_one(t_list *list)
{
	printf("Lütfen notunuzun saklanacağı dosya için bir isim girin: ");
	usleep(20);
	scanf (" %[^\n]", list->str);
	usleep(20);
	list->w_file = open((const char *)list->str, O_CREAT | O_WRONLY, 333);
	printf ("Şimdi ise şifreli bir şekilde kaydedilmesini istediğiniz notunuzu giriniz:\n");
	usleep(20);
	scanf (" %[^\n]", list->str);
	usleep(20);
	list->str = (char *)ft_encryption((unsigned char *)list->str);
	write (list->w_file, list->str, ft_strlen(list->str));
	usleep(50);
	system("clear");
	free(list->str);
	list->str = NULL;
	printf("Notunuz şifreleniyor...\n");
	sleep(1);
	system("clear");
	printf("Notunuz başarıyla şifrelendi.\n");
	close (list->w_file);
	list->str = (char *)calloc(1000, 1000);
	if (!list->str)
	{
		printf("Bellek tahsisi yapılamadı... Program kapatılıyor\n");
		ft_closer(list);
		sleep(1);
		system("clear");
		exit(0);
	}
	any_other(list);
}

void	any_other(t_list *list)
{
	printf("\nBaşka bir işlem yapmak istiyorsanız 'evet', istemiyorsanız 'hayır' yazınız: ");
	usleep(20);
	scanf (" %[^\n]", list->str);
	yes_or_no(list);
	chooser(list);
}

void	ch_two_continue(t_list *list)
{
	while (1)
	{
		list->r_file = open((const char *)list->str, O_RDONLY, 444);
		if (list->r_file == -1)
		{
			system("clear");
			printf("Hatalı dosya adı girdiniz ya da var olmayan dosya...\nLütfen tekrar giriş yapınız: ");
			system("ls");
			usleep(20);
			scanf (" %[^\n]", list->str);
			usleep(20);
		}
		else
			break ;
	}
	sleep(1);
	printf("Okuma işlemi tamamlandı. Şifreleme çözümlendi.\nMetni yazdırmak için 'oku' yazınız: ");
	usleep(20);
	scanf (" %[^\n]", list->str);
	usleep(20);
	want_read(list);
	any_other(list);
}

void	ch_two(t_list *list)
{
	printf("Okuyabileceğiniz dosyalar\n");
	system("ls");
	usleep(20);
	scanf (" %[^\n]", list->str);
	usleep(20);
	if (ft_strcmp((char *)".pss", list->str) == 0)
	{
		printf("Şifre dosyanızı okuyamazsınız!\nProgram sonlandırılıyor!\n");
		ft_closer(list);
		sleep(1);
		system("clear");
		exit(1);
	}
	else
		ch_two_continue(list);
}

void	chooser(t_list *list)
{
	if (list->choose == 0)
	{
		printf("\nNotlarınız güvende, programdan çıkılıyor... Sağlıklı kalın :)\n");
		ft_closer(list);
		sleep(1);
		system("clear");
		exit(0);
	}
	else if (list->choose == 1)
		ch_one(list);
	else if (list->choose == 2)
		ch_two(list);
	else
		list->choose = ft_error(list->str, list->choose);
}
