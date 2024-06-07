/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:15:37 by sreo              #+#    #+#             */
/*   Updated: 2024/06/07 14:14:27 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strs;
	int		i;

	i = 0;
	strs = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (strs == NULL)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	while (s1[i])
	{
		strs[i] = s1[i];
		i++;
	}
	strs[i] = '\0';
	ft_strcat(strs, s2);
	free(s1);
	return (strs);
}

char	*ft_strchr(const char *string, int c)
{
	int		i;
	char	cc;

	i = 0;
	cc = c;
	if (!string)
		return (0);
	while (string[i])
	{
		if (string[i] == cc)
			return ((char *)&string[i]);
		i++;
	}
	if (string[i] == cc)
		return ((char *)&string[i]);
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*p;

	i = -1;
	len = ft_strlen(src);
	p = (char *)malloc(sizeof(char) * len + 1);
	if (p == NULL)
		return (NULL);
	while (++i < len)
		p[i] = src[i];
	p[i] = '\0';
	return (p);
}
