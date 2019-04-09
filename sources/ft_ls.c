/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:39:21 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/09 20:35:45 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void free_ls(t_ls **ls)
{
    if (ls == NULL)
        return ;
    else
        ft_memdel((void**)ls);
}

static t_ls *get_arguments(t_ls *ls, int argc, char **argv)
{
    int     x;

    x = 1;
    while (x < argc)
    {
        if (!get_flags(argv[x], ls))
        {
            free_ls(&ls);
            exit(EXIT_FAILURE);
        }
        else
            break ;
        x++;
    }
    if (x < argc)
        ls->direct = ft_strdup(argv[x]);
    else   
        ls->direct = ft_strdup("./");
    return(ls);
}

static char *find_way(char *way, char *dir)
{
    if (!way || (way && !*way))
        return(way = ft_strdup(dir));
    else
        return(way = ft_strjoin(ft_strjoin(way, "/"), dir));
}

static int  initialization(t_arg *argument)
{
    if (argument)
    {
        if(!(argument = (t_arg*)malloc(sizeof(t_arg))))
        {
            mal_error();
            return(0);
        }
        return(1);
    }
    else
        return(0);
}

bool    find_hidden_fd(t_ls *ls, char *line)
{
    if (ls->flags.a)
        return(false);
    else if (*str == '.')
        return(true);
    else
        return(false);
}

void addition(t_arg *list, t_dir *direct, t_arg **list_ptr)
{
    t_arg   *curr;

    if((*list_ptr)->name)
    {
        if (!(curr = (t_arg*)malloc(sizeof(t_arg))))
            mal_error();
    }
    (*list_ptr)->next = curr;
    curr->blocks = (*list_ptr)->blocks;
    curr->way = (*list_ptr)->way;
    *list_ptr = (*list_ptr)->next;
    else
        return ;
}

int ft_ls(t_ls *ls)
{
    DIR     *fd;
    t_dir   *direct;
    t_arg   *memorized;
    t_arg   *list;

    if (!(fd = opendir(ls->direct)))
        return(direct_error());
    if (!initialization(&list))
        return(init_error());
    memorized = list;
    list->way = find_way(list->way, ls->direct);
    while ((direct = readdir(fd) || closedir(fd)))
    {
        if(find_hidden_fd(ls, direct->d_name);
            continue ;
        list->info = ls;
        addition(list, dirent, &list);
        if (list->next_arg)
            list = list->next_arg;
    }
    }
}

int main(int argc, char **argv)
{
    t_ls    *ls;

    if (!(ls = (t_ls *)malloc(sizeof(t_ls))))
        mal_error();
    get_arguments(ls, argc, argv);
    return (ft_ls(ls));
}