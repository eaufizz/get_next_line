/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:19:11 by sreo              #+#    #+#             */
/*   Updated: 2024/05/20 00:29:55 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int skipstr(char *str, int count)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while(i < count)
    {
        while(str[j] != '\n')
            j++;
        i++;
        j++;
    }
    return j;
}

int countlen(char *str, int i)
{
    int len;

    len = 0;
    while(str[i] != '\n')
    {
        i++;
        len ++;
    }
    return len;
}

char *getstr(char *str, int count)
{
    int i;
    int j;
    int len;
    char *result;
    
    i = skipstr(str, count);
    j = 0;
    len = countlen(str, count);
    result = malloc(sizeof(char) * (len + 1));
    if(result == NULL)
        return NULL;
    while(str[i + j] != '\n')
    {
        result[j] = str[i + j];
        j++;
    }
    result[j] = '\0';
    return result;
}