/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:41:27 by shamzaou          #+#    #+#             */
/*   Updated: 2022/12/21 19:42:45 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    char *line;
    int fd1;
    int fd2;

    fd1 = open("files/textf", 0);
    fd2 = open("files/text1", 0);
    line = get_next_line(fd1);
    printf("%s", line);
    line = get_next_line(fd2);
    printf("%s", line);
    line = get_next_line(fd1);
    printf("%s", line);
    
}
