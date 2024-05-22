#include "library.h"

int	pss_creator(int pss, char *reader, char *reader_control)
{
	while (1)
	{
		if (ft_strcmp(reader, reader_control) == 0)
		{
			system("touch .pss");
			system("chmod 777 .pss");
			pss = open(".pss", O_WRONLY, 777);
			reader = (char *)ft_encryption((unsigned char *)reader);
			write (pss, reader, ft_strlen(reader));
			close(pss);
			printf("Şifreniz oluşturuldu. Uygulamaya giriş yapılıyor...\n");
			sleep(1);
			close(pss);
			system("clear");
			system("chmod 000 .pss");
			break ;
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

int	pss_control(char *reader, char *reader_control)
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
			break ;
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

int	if_pss_true(t_list *list, int controller)
{
	system("chmod 777 .pss");
	list->pss = open(".pss", O_RDONLY, 777);
	printf("Uygulamayı açmak için lütfen şifrenizi giriniz:");
	usleep(20);
	scanf (" %[^\n]", list->reader_control);
	usleep(20);
	free(list->reader);
	list->reader = NULL;
	list->reader = ft_get_read(list->pss, list->reader);
	list->reader = (char *)ft_decryption((unsigned char *)list->reader);
	close (list->pss);
	system("chmod 000 .pss");
	controller = pss_control(list->reader, list->reader_control);
	return (controller);
}