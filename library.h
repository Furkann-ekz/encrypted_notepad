#ifndef LIBRARY_H
# define LIBRARY_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 79
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void			ft_closer(unsigned char *str);
void			close_files(int yazilacak_dosya, int okunacak_dosya, int pss);
unsigned char	*ft_encryption(unsigned char *str);
unsigned char	*ft_decryption(unsigned char *str);
unsigned char	*ft_str(unsigned char *str);
unsigned char	*ft_strjoin(unsigned char *s1, unsigned char *s2);
unsigned char	*ft_get_read(int fd, unsigned char *str);
int				ft_strcmp(unsigned char *s1, unsigned char *s2);
int				ft_strncmp(unsigned char *s1, unsigned char *s2, int size);
int				ft_error(unsigned char *str, int secim);
int				ft_choose(unsigned char *str, int secim);
int				pss_creator(int pss, unsigned char *s, unsigned char *temp, unsigned char *str);
int				pss_error(char *str, char *temp);
size_t			ft_strlen(unsigned char *str);

#endif
