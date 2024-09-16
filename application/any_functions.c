#include "library.h"

int	pss_creator(int pss, unsigned char *reader, unsigned char *reader_control)
{
	while (1)
	{
		if (ft_strcmp(reader, reader_control) == 0)
		{
			system("touch .pss");
			system("chmod 777 .pss");
			pss = open(".pss", O_WRONLY, 777);
			reader = ft_encryption(reader);
			write (pss, reader, ft_strlen(reader));
			close(pss);
			printf("Şifreniz oluşturuldu. Uygulamaya giriş yapılıyor...\n");
			sleep(1);
			close(pss);
			system("clear");
			system("chmod 000 .pss");
			break;
		}
		else
		{
			sleep(1);
			system("clear");
			printf("Girdiğiniz şifreler birbiriyle uyuşmuyor. Lütfen tekrar deneyiniz:");
			usleep(20);
			scanf (" %[^\n]", reader);
			usleep(20);
			printf("Onaylamak için şifrenizi tekrar giriniz:");
			usleep(20);
			scanf (" %[^\n]", reader_control);
			usleep(20);
		}
	}
	return (0);
}

int	pss_control(unsigned char *reader, unsigned char *reader_control)
{
	int	x;

	x = 3;
	while (1)
	{
		if (ft_strcmp(reader, reader_control) == 0)
		{
			printf("Şifre doğru! Uygulama açılıyor...\n");
			sleep(1);
			system("clear");
			break;
		}
		system("clear");
		x--;
		if (x == 0)
		{
			system("clear");
			printf("3. kez hatalı şifre girdiniz!\nProgram sonlandırılıyor...\n");
			return (0);
		}
		printf("Hatalı şifre girdiniz!\n%d deneme hakkınız kaldı...\n", x);
		usleep(20);
		scanf (" %[^\n]", reader_control);
		usleep(20);
	}
	return (1);
}

void	list_starter(t_list *list)
{
	list->r_file = 0;
	list->w_file = 0;
	list->choose = 0;
	list->pss = 0;
	list->reader = NULL;
	list->reader_control = NULL;
	list->str = NULL;
}

int	pss_creat(t_list *list)
{
	printf("Uygulamayı ilk kez kullanıyorsanız bir şifre oluşturmanız gerekmektedir.\n"
			"Lütfen şifrenizi giriniz:");
	usleep(20);
	if (list->str)
		free(list->str);
	list->str = NULL;
	list->str = malloc(100);
	if (!list->str)
	{
		printf("Bellek tahsisi yapılamadı... Program sonlandırılıyor.\n");
		ft_closer(list);
	}
	usleep(20);
	scanf (" %[^\n]", list->reader);
	usleep(20);
	printf("Onaylamak için şifrenizi tekrar giriniz:");
	usleep(20);
	scanf (" %[^\n]", list->reader_control);
	usleep(20);
	pss_creator(list->pss, list->reader, list->reader_control);
	return (0);
}

int	ft_error(unsigned char *str, int choose)
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

void	ft_closer(t_list *list)
{
	if(list->r_file)
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
	while ((ft_strcmp(list->str, (unsigned char *)"evet") != 0) && (ft_strcmp(list->str, (unsigned char *)"hayır") != 0))
	{
		system("clear");
		printf("Hatalı giriş yaptınız.\n"
			"Başka bir işlem yapmak istiyorsanız 'evet', istemiyorsanız 'hayır' yazınız: ");
		usleep(20);
		scanf (" %[^\n]", list->str);
		usleep(20);
	}
}

void	yes_or_no(t_list *list)
{
	while (1)
	{
		if (ft_strcmp(list->str, (unsigned char *)"evet") == 0)
		{
			system("clear");
			list->choose = ft_choose(list);
			break;
		}
		else if (ft_strcmp(list->str, (unsigned char *)"hayır") == 0)
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
	printf("Şimdi ise şifreli bir şekilde kaydedilmesini istediğiniz notunuzu giriniz:\n");
	usleep(20);
	scanf (" %[^\n]", list->str);
	usleep(20);
	list->str = ft_encryption(list->str);
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
	list->str = (unsigned char *)calloc(1000, 1000);
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
	system("clear");
	printf("Başka bir işlem yapmak istiyorsanız 'evet', istemiyorsanız 'hayır' yazınız: ");
	usleep(20);
	scanf (" %[^\n]", list->str);
	yes_or_no(list);
	chooser(list);
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
		if (ft_strcmp(list->str, (unsigned char *)"oku") == 0)
		{
			free(list->str);
			list->str = NULL;
			list->str = (unsigned char *)calloc(1000, 1000);
			list->str = ft_get_read(list->r_file, list->str);
			list->str = ft_decryption(list->str);
			close (list->r_file);
			system("clear");
			printf("%s\n", list->str);
			sleep(10);
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
	if (ft_strcmp((unsigned char *)".pss", list->str) == 0)
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
