/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:46:52 by fekiz             #+#    #+#             */
/*   Updated: 2023/12/29 09:36:30 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
# define LIBRARY_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 79
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	ft_closer(unsigned char *str, int yazilacak_dosya, int okunacak_dosya, int pss);


unsigned char	*ft_encryption(unsigned char *str);
unsigned char	*ft_decryption(unsigned char *str);
unsigned char	*ft_str(unsigned char *str);
unsigned char	*ft_strjoin(unsigned char *s1, unsigned char *s2);
unsigned char	*ft_get_read(int fd, unsigned char *str);

int		ft_strcmp(unsigned char *s1, unsigned char *s2);
int		ft_strncmp(unsigned char *s1, unsigned char *s2, int size);
int		ft_error(unsigned char *str, int secim);
int		ft_secim(unsigned char *str, int secim);

size_t	ft_strlen(unsigned char *str);


#endif
