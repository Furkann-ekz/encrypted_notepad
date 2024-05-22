#ifndef LIBRARY_H
# define LIBRARY_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include "../mlx/mlx.h"

typedef struct list
{
	int				r_file;
	int				w_file;
	int				pss;
	int				choose;
	char			*reader;
	char			*reader_control;
	char			*str;
	struct termios	old;
	struct termios	new;
}					t_list;

int				pss_creator(int pss, char *temp, char *str);
int				ft_strcmp(char *s1, char *s2);
int				pss_control(char *reader, char *reader_control);
int				pss_creat(t_list *list);
int				ft_choose(t_list *list);
int				ft_error(char *str, int choose);
int				if_pss_true(t_list *list, int controller);

size_t			ft_strlen(char *str);

void			chooser(t_list *list);
void			ch_two(t_list *list);
void			ch_two_continue(t_list *list);
void			any_other(t_list *list);
void			ft_closer(t_list *list);
void			list_starter(t_list *list);
void			ch_one(t_list *list);
void			yes_or_no(t_list *list);
void			wrong_str(t_list *list);
void			any_other(t_list *list);
void			want_read(t_list *list);

unsigned char	*ft_encryption(unsigned char *str);
unsigned char	*ft_decryption(unsigned char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_get_read(int fd, char *str);

#endif
