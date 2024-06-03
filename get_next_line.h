/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:20:11 by sreo              #+#    #+#             */
/*   Updated: 2024/06/03 22:14:46 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
static char	*ft_strcat(char *dest, const char *src);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(const char *string, int c);

#endif