/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:41:27 by shamzaou          #+#    #+#             */
/*   Updated: 2022/12/21 01:44:57 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    char *line;
    int fd;

    fd = open("files/textf", 0);
    line = NULL;
    while ( 1 )
    {
        line = get_next_line(fd);
        
        if (line == NULL)
            break;
        printf("%s", line);
        free(line);
    }
}
