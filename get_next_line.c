/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:04:47 by sreo              #+#    #+#             */
/*   Updated: 2024/06/07 14:36:00 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readfd(int fd, char *temp)
{
	char	*buf;
	int		i;
	int		j;

	i = 1;
	j = 0;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!ft_strchr(temp, '\n') && i != 0 && ++j)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1 || (j == 1 && i == 0 && temp[0] == '\0') || !buf)
		{
			free(buf);
			free(temp);
			return (NULL);
		}
		buf[i] = '\0';
		temp = ft_strjoin(temp, buf);
		if (temp == NULL)
			return (NULL);
	}
	free(buf);
	return (temp);
}

char	*readline(char *temp)
{
	int		i;
	char	*result;

	i = 0;
	while (temp[i] != '\n' && temp[i])
		i++;
	result = malloc(sizeof(char) * (i + 2));
	if (result == NULL)
	{
		free(temp);
		return (NULL);
	}
	i = 0;
	while (temp[i] != '\n' && temp[i])
	{
		result[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
	{
		result[i] = temp[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*trimtemp(char *temp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (temp[i] != '\n' && temp[i])
		i++;
	if (temp[i] == '\n')
		i++;
	while (temp[i + j])
		j++;
	str = malloc(sizeof(char) * (j + 1));
	j = 0;
	while (temp[i + j] && str != NULL)
	{
		str[j] = temp[i + j];
		j++;
	}
	if (str != NULL)
		str[j] = '\0';
	free(temp);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*temp;

	if (temp == NULL)
	{
		temp = ft_strdup("");
		if (temp == NULL)
			return (NULL);
	}
	temp = readfd(fd, temp);
	if (temp == NULL)
	{
		free(temp);
		return (NULL);
	}
	result = readline(temp);
	if (result == NULL)
		return (NULL);
	temp = trimtemp(temp);
	if (temp == NULL)
		free(temp);
	if (!temp && !result)
		return (NULL);
	return (result);
}
