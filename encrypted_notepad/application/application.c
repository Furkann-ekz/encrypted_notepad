#include "library.h"

int	main(void)
{
	t_list	*list;
	int		controller;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (printf("Bellek tahsisi yapılamadı... Program kapatılıyor\n"), 0);
	system("clear");
	list_starter(list);
	list->reader_control = (unsigned char *)calloc(1000, 1000);
	list->reader = (unsigned char *)calloc(1000, 1000);
	list->str = (unsigned char *)calloc(1000, 1000);
	if (!list->reader || !list->reader_control || !list->str)
		return (printf("Bellek tahsisi yapılamadı... Program kapatılıyor\n"), 0);
	printf("Merhaba, şifreli not defteri uygualamamıza hoş geldiniz!\n");
	if (access(".pss", F_OK) == -1)
	{
		if (pss_creat(list) == 1)
			return (0);
	}
	else
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
		list->reader = ft_decryption(list->reader);
		close (list->pss);
		controller = pss_control(list->reader, list->reader_control);
		system("chmod 000 .pss");
		if (controller == 0)
		{
			ft_closer(list);
			exit(0);
		}
	}
	list->choose = ft_choose(list);
	chooser(list);
}
