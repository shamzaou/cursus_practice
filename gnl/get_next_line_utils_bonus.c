/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:32:54 by shamzaou          #+#    #+#             */
/*   Updated: 2022/12/28 16:07:59 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int nl_found(t_gnl *stash)
{
    t_gnl   *current;
    int     i;
    
    if (!stash)
        return (0);
    current = ft_lst_get_last(stash);
    i = 0;
    while (current->content[i])
    {
        if (current->content[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

t_gnl   *ft_lst_get_last(t_gnl *stash)
{
    t_gnl   *current;

    current = stash;
    while (current && current->next)
        current = current->next;
    return (current);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

void    free_stash(t_gnl *stash)
{
    t_gnl   *current;
    t_gnl   *next;

    current = stash;
    while (current)
    {
        free(current->content);
        next = current->next;
        free(current);
        current = next;
    }
}

void    ft_broomstick(t_gnl **stash)
{
    t_gnl   *last;
    t_gnl   *clean_node;
    int     i;
    int     j;

    clean_node = malloc(sizeof(t_gnl));
    if (stash == NULL || clean_node == NULL)
        return;
    clean_node->content = NULL;
    clean_node->next = NULL;
    last = ft_lst_get_last(*stash);
    i = 0;
    while (last->content[i] && last->content[i] != '\n')
        i++;
    if (last->content && last->content[i] == '\n')
        i++;
    clean_node->content = malloc(sizeof(char) * ((ft_strlen(last->content) - i) + 1));
    if (clean_node->content == NULL)
        return;
    j = 0;
    while (last->content[i])
        clean_node->content[j++] = last->content[i++];
    clean_node->content[j] = '\0';
    free_stash(*stash);
    *stash = clean_node;
}
