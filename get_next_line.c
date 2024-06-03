/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:04:47 by sreo              #+#    #+#             */
/*   Updated: 2024/06/03 22:13:26 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *readfd(int fd, char *temp)
{
	char *buf;
	int i;
	
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(buf == NULL)
		return NULL;
	while(!ft_strchr(temp, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
		temp = ft_strjoin(temp, buf);
	}
	free(buf);
	return temp;
}

char *readline(char *temp)
{
	int i;
	char *result;

	i = 0;
	while(temp[i] != '\n' && temp[i])
		i++;
	result = malloc(sizeof(char) * (i + 2));
	if(result == NULL)
		return NULL;
	i = 0;
	while(temp[i] != '\n' && temp[i])
	{
		result[i] = temp[i];
		i++;
	}
	result[i] = '\n';
	result[i + 1] = '\0';
	return result;
}

char *trimtemp(char *temp)
{
	int i;
	int j;
	char *str;
	
	i = 0;
	j = 0;
	while(temp[i] != '\n')
		i++;
	i++;
	while(temp[i+j])
		j++;
	str = malloc(sizeof(char) * (j + 1));
	j = 0;
	while(temp[i+j])
	{
		str[j] = temp[i+j];
		j++;
	}
	str[j] = '\0';
	free(temp);
	return str;
	
}

char *get_next_line(int fd)
{
	char *result;
	static char *temp;
	
	temp = readfd(fd, temp);
	result = readline(temp);
	temp = trimtemp(temp);
	return result;
}
