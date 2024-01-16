#include "library.h"

int	ft_error(unsigned char *str, int secim)
{
	secim = 3;
	while (secim != 0 && secim != 1 && secim != 2)
	{
		system("clear");
		str = ft_str("Geçersiz giriş yaptınız. "
				"Lütfen sadece 0-1-2 değerleri arasından giriş yapınız.\n"
				"Notunuzu şifrelemek için 1,\n"
				"Şifrelediğiniz bir notu okumak için 2,\n"
				"Programı kapatmak için 0 girmeniz gerekmektedir: ");
		write (1, str, ft_strlen(str));
		free(str);
		usleep(100);
		scanf (" %[^\n]", str);
		usleep(100);
		while (getchar() != '\n')
			;
		if (!str[1])
			secim = str[0] - 48;
	}
	return (secim);
}

void	ft_closer(unsigned char *str)
{
	str = NULL;
	str = ft_str("\nNotlarınız güvende, programdan çıkılıyor... "
			"Sağlıklı kalın :)\n");
	write (1, str, ft_strlen(str));
	free(str);
}

void	close_files(int yazilacak_dosya, int okunacak_dosya, int pss)
{
	if (yazilacak_dosya == 3 || yazilacak_dosya == 4 || yazilacak_dosya == 5)
		close(yazilacak_dosya);
	if (okunacak_dosya == 3 || okunacak_dosya == 4 || okunacak_dosya == 5)
		close(okunacak_dosya);
	if (pss == 3 || pss == 4 || pss == 5)
		close(pss);
	sleep(1);
	system("clear");
}

int	ft_choose(unsigned char *str, int secim)
{
	secim = 31;
	str = ft_str("Lütfen yapmak istediğiniz işlemi seçiniz;\n"
			"Notunuzu şifrelemek için 1,\n"
			"Şifrelediğiniz bir notu okumak için 2,\n"
			"Programı kapatmak için 0 girmeniz gerekmektedir: ");
	write (1, str, ft_strlen(str));
	free(str);
	usleep(20);
	scanf (" %[^\n]", str);
	usleep(20);
	while (getchar() != '\n');
	if (!str[1])
		secim = str[0] - 48;
	if (secim != 1 && secim != 2 && secim != 0)
	{
		str = NULL;
		secim = ft_error(str, secim);
	}
	str = NULL;
	return (secim);
}
int	pss_creator(int pss, unsigned char *s, unsigned char *temp, unsigned char *str)
{
	int	c;

	c = 1;;
	if (ft_strcmp(temp, str) == 0)
	{
		pss = open(".pss", O_CREAT | O_WRONLY, 777);
		str = ft_encryption(str);
		write (pss, str, ft_strlen(str));
		close(pss);
		temp = ft_str("Şifreniz oluşturuldu. Uygulamaya giriş yapılıyor...\n");
		write (1, temp, ft_strlen(temp));
		sleep(2);
		system("clear");
		c = 0;
	}
	while (c)
	{
		sleep(1);
		system("clear");
		s = ft_str("Girdiğiniz şifreler birbiriyle uyuşmuyor. Lütfen tekrar deneyiniz:");
		write (1, s, ft_strlen(s));
		free(s);
		usleep(20);
		scanf (" %[^\n]", str);
		usleep(20);
		temp = ft_str("Onaylamak için şifrenizi tekrar giriniz:");
		write (1, temp, ft_strlen(temp));
		free(temp);
		usleep(20);
		scanf (" %[^\n]", temp);
		usleep(20);
		if (ft_strcmp(temp, str) == 0)
			break ;
	}
	return (0);
}

int	pss_error(unsigned char *str, unsigned char *temp)
{
	int	c;
	int	x;
	x = 3;
	c = 1;
	while (c)
	{
		if (ft_strcmp(str, temp) == 0)
		{
			free(str);
			str = ft_str("Şifre doğru! Uygulama açılıyor...");
			write (1, str, ft_strlen(str));
			free(str);
			sleep(1);
			system("clear");
			c = 0;
		}
		else
		{
			system("clear");
			x--;
			if (x == 0)
			{
				system("clear");
				temp = NULL;
				temp = ft_str("3. kez hatalı şifre girdiniz!\n"
						"Program sonlandırılıyor...\n");
				write (1, temp, ft_strlen(temp));
				free(temp);
				return (0);
			}
			printf("Hatalı şifre girdiniz!\n%d deneme hakkınız kaldı...\n", x);
			usleep(20);
			scanf (" %[^\n]", temp);
			usleep(20);
		}
	}
}

int	signal_handler(int sig)
{
	if (sig == SIGINT || sig == SIGKILL)
		return (1);
	return (0);
}

int	main(void)
{
	int				yazilacak_dosya;
	int				okunacak_dosya;
	int				pss;
	int				secim;
	int				c;
	unsigned char	*str;
	unsigned char	*temp;
	unsigned char	*s;

	system("clear");
	str = ft_str("Merhaba, şifreli not defteri uygualamamıza hoş geldiniz!\n");
	write (1, str, ft_strlen(str));
	free(str);
	if (access(".pss", F_OK) == -1)
	{
		str = ft_str("Uygulamayı ilk kez kullanıyorsanız bir şifre oluşturmanız gerekmektedir.\n"
				"Lütfen şifrenizi giriniz:");
		write (1, str, ft_strlen(str));
		free(str);
		usleep(20);
		scanf (" %[^\n]", str);
		usleep(20);
		temp = ft_str("Onaylamak için şifrenizi tekrar giriniz:");
		write (1, temp, ft_strlen(temp));
		free(temp);
		usleep(20);
		scanf (" %[^\n]", temp);
		usleep(20);
		pss_creator(pss, s, temp, str);
	}
	else
	{
		pss = open(".pss", O_RDONLY, 777);
		temp = ft_str("Uygulamayı açmak için lütfen şifrenizi giriniz:");
		write (1, temp, ft_strlen(temp));
		free(temp);
		usleep(20);
		scanf (" %[^\n]", temp);
		usleep(20);
		str = NULL;
		str = ft_get_read(pss, str);
		str = ft_decryption(str);
		c = pss_error(str, temp);
		if (c == 0)
		{
			close_files(yazilacak_dosya, okunacak_dosya, pss);
			exit(1);
		}
	}
	str = NULL;
	secim = ft_choose(str, secim);
	while (1)
	{
		if (secim != 1 && secim != 2 && secim != 0)
		{
			str = NULL;
			secim = ft_error(str, secim);
		}
		if (secim == 0)
		{
			ft_closer(str);
			close_files(yazilacak_dosya, okunacak_dosya, pss);
			break ;
		}
		else if (secim == 1)
		{
			secim = 3;
			if (yazilacak_dosya == 3 || yazilacak_dosya == 4)
				close(yazilacak_dosya);
			if (okunacak_dosya == 3 || okunacak_dosya == 4)
				close(okunacak_dosya);
			str = ft_str("Lütfen notunuzun saklanacağı "
					"dosya için bir isim girin: ");
			write (1, str, ft_strlen(str));
			free(str);
			usleep(20);
			scanf (" %[^\n]", str);
			usleep(20);
			yazilacak_dosya = open(str, O_CREAT | O_WRONLY, 333);
			str = ft_str("Şimdi ise şifreli bir şekilde kaydedilmesini"
					" istediğiniz notunuzu giriniz:\n");
			write (1, str, ft_strlen(str));
			free(str);
			usleep(20);
			scanf (" %[^\n]", str);
			usleep(20);
			str = ft_encryption(str);
			write (yazilacak_dosya, str, ft_strlen(str));
			usleep(50);
			system("clear");
			str = NULL;
			str = ft_str("Notunuz şifreleniyor...");
			write (1, str, ft_strlen(str));
			free(str);
			sleep(1);
			system("clear");
			str = ft_str("Notunuz başarıyla şifrelendi.\n"
					"Başka bir işlem yapmak istiyorsanız 'evet'"
					", istemiyorsanız 'hayır' yazınız: ");
			write (1, str, ft_strlen(str));
			free (str);
			usleep(20);
			scanf (" %[^\n]", str);
			usleep(20);
			while (1)
			{
				if (ft_strcmp(str, "evet") == 0)
				{
					system("clear");
					str = NULL;
					secim = ft_choose(str, secim);
					str = NULL;
					break ;
				}
				else if (ft_strcmp(str, "hayır") == 0)
				{
					str = NULL;
					ft_closer(str);
					close_files(yazilacak_dosya, okunacak_dosya, pss);
					str = NULL;
					return (0);
				}
				else
				{
					while ((ft_strcmp(str, "evet") != 0) && (ft_strcmp(str, "hayır") != 0))
					{
						system("clear");
						str = NULL;
						str = ft_str("Hatalı giriş yaptınız.\n"
								"Başka bir işlem yapmak istiyorsanız 'evet'"
								", istemiyorsanız 'hayır' yazınız: ");
						write (1, str, ft_strlen(str));
						free(str);
						usleep(20);
						scanf (" %[^\n]", str);
						usleep(20);
					}
				}
			}
			str = NULL;
		}
		else if (secim == 2)
		{
			secim = 3;
			if (yazilacak_dosya == 3 || yazilacak_dosya == 4 || yazilacak_dosya == 5)
				close (yazilacak_dosya);
			if (okunacak_dosya == 3 || okunacak_dosya == 4 || okunacak_dosya == 5)
				close(okunacak_dosya);
			if (pss == 3 || pss == 4 || pss == 5)
				close(pss);
			str = NULL;
			str = ft_str("Lütfen okumak istediğiniz dosyanın adını giriniz: ");
			write (1, str, ft_strlen(str));
			free(str);
			usleep(20);
			scanf (" %[^\n]", str);
			usleep(20);
			while (1)
			{
				okunacak_dosya = open(str, O_RDONLY, 444);
				if (okunacak_dosya == -1)
				{
					str = NULL;
					system("clear");
					str = ft_str("Hatalı dosya adı girdiniz ya da var olmayan dosya...\n"
							"Lütfen tekrar giriş yapınız: ");
					write (1, str, ft_strlen(str));
					free(str);
					usleep(20);
					scanf (" %[^\n]", str);
					usleep(20);
				}
				else
					break ;
			}
			sleep(1);
			temp = ft_str("Okuma işlemi tamamlandı. Şifreleme çözümlendi.\n"
					"Metni yazdırmak için 'oku' yazınız: ");
			write (1, temp, ft_strlen(temp));
			free(temp);
			usleep(20);
			scanf (" %[^\n]", temp);
			usleep(20);
			while (1)
			{
				if (ft_strncmp(temp, "oku", 3) == 0)
				{
					system ("clear");
					str = NULL;
					str = ft_get_read(okunacak_dosya, str);
					str = ft_decryption(str);
					write (1, str, ft_strlen(str));
					write (1, "\n", 1);
					free(str);
					str = ft_str("Başka bir işlem yapmak istiyorsanız 'evet'"
							", istemiyorsanız 'hayır' yazınız: ");
					write (1, str, ft_strlen(str));
					free (str);
					usleep(20);
					scanf (" %[^\n]", str);
					usleep(20);
					while (1)
					{
						if (ft_strcmp(str, "evet") == 0)
						{
							secim = ft_choose(temp, secim);
							temp = NULL;
							break ;
						}
						else if (ft_strcmp(str, "hayır") == 0)
						{
							str = NULL;
							ft_closer(str);
							close_files(yazilacak_dosya, okunacak_dosya, pss);
							str = NULL;
							return (0);
						}
						else
						{
							while ((ft_strcmp(str, "evet") != 0) && (ft_strcmp(str, "hayır") != 0))
							{
								system("clear");
								str = NULL;
								str = ft_str("Hatalı giriş yaptınız.\n"
										"Başka bir işlem yapmak istiyorsanız 'evet'"
										", istemiyorsanız 'hayır' yazınız: ");
								write (1, str, ft_strlen(str));
								free(str);
								usleep(20);
								scanf (" %[^\n]", str);
								usleep(20);
							}
						}
					}
					if (ft_strcmp(str, "evet") == 0)
						break;
				}
				else
				{
					system("clear");
					str = NULL;
					str = ft_str("Hatalı giriş yaptınız.\nLütfen notunuzu görüntülemek için 'oku' yazınız: ");
					write (1, str, ft_strlen(str));
					free(str);
					usleep(20);
					scanf (" %[^\n]", temp);
					usleep(20);
				}
			}
		}
	}
	c = (int)signal(SIGINT, signal_handler);
	c = (int)signal(SIGKILL, signal_handler);
	if (c == 1)
	{
		ft_closer(str);
		close_files(yazilacak_dosya, okunacak_dosya, pss);
		exit (0);
	}
}
