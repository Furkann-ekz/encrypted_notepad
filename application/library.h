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

typedef struct list
{
	int				r_file;
	int				w_file;
	int				pss;
	int				choose;
	unsigned char	*reader;
	unsigned char	*reader_control;
	unsigned char	*str;
	struct termios	old, new;
}				t_list;

// Password Creator
int				pss_creator(int pss, unsigned char *temp, unsigned char *str);
int				ft_strcmp(unsigned char *s1, unsigned char *s2);
int				pss_control(unsigned char *reader, unsigned char *reader_control);
int				pss_creat(t_list *list);
int				ft_choose(t_list *list);
int				ft_error(unsigned char *str, int choose);

size_t			ft_strlen(unsigned char *str);

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
void			old_terminal(t_list *list);
void			new_terminal(t_list *list);

unsigned char	*ft_encryption(unsigned char *str);
unsigned char	*ft_decryption(unsigned char *str);
unsigned char	*ft_strjoin(unsigned char *s1, unsigned char *s2);
unsigned char	*ft_get_read(int fd, unsigned char *str);

#endif
