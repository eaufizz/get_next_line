/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:50:03 by sreo              #+#    #+#             */
/*   Updated: 2024/05/20 00:30:22 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd;
    char *str;
    
    fd = open("test.txt", O_RDWR);
    str = get_next_line(fd);
    printf("%s\n", str);
    str = get_next_line(fd);
    printf("%s\n", str);
    str = get_next_line(fd);
    printf("%s\n", str);
    close(fd);
    free(str);
    return 0;
}