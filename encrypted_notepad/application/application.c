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
	printf("Merhaba, şifreli not defteri uygualamamıza hoş geldiniz!\n");
	if (access(".pss", F_OK) == -1)
	{
		if (pss_creat(list) == 1)
			return (0);
	}
	else
	{
		controller = if_pss_true(list, controller);
		if (controller == 0)
			return (ft_closer(list), 0);
	}
	list->choose = ft_choose(list);
	chooser(list);
}
