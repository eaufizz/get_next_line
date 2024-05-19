/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:04:47 by sreo              #+#    #+#             */
/*   Updated: 2024/05/19 23:09:34 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define SIZE 1024

char *get_next_line(int fd)
{
    char *result;
    char textdata[SIZE];
    static int fdtemp;
    static int count;
    
    if(fdtemp != fd)
    {
        count == 0;
        fdtemp = fd;
    }
    count++;
    read(fd, textdata, SIZE);
    result = getstr(textdata, count);
    return result;
}
