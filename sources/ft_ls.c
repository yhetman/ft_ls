/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:39:21 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/10 21:26:05 by yhetman          ###   ########.fr       */
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

/* int  initialization(t_arg **argument)
{
    if (argument)
    {
        if(!(*argument = (t_arg*)malloc(sizeof(t_arg))))
        {
            mal_error();
            return(0);
        }
        return(1);
    }
    else
        return(0);
}
*/

bool    find_hidden_fd(t_ls *ls, char *line)
{
    if (ls->flags.a)
        return(false);
    else if (*line == '.')
        return(true);
    else
        return(false);
}

bool    statistic(t_arg *curr)
{
    int         len;
    t_stat      *buff;
    t_passwd    *p;
    t_group     *grp;

    if (!(buff = (t_stat*)malloc(sizeof(t_stat)))
        || !(p = (t_passwd*)malloc(sizeof(t_passwd)))
        || !(grp = (t_group*)malloc(sizeof(t_group))))
        mal_error();
    if (lstat(find_way(curr->way, curr->name), buff) < 0)
        link_error();
    curr->buff = buff;
    len = ft_nbrlen(curr->buff->st_size);
    p = getpwuid(curr->buff->st_uid);
    if (curr->info->longest < len)
        curr->info->longest = len;
    len = ft_strlen(p->pw_name);
    if (curr->info->longest_w < len)
        curr->info->longest_w = len;
    grp = getgrgid(curr->buff->st_gid);
    len = ft_strlen(grp->gr_name);
    if (curr->info->longest_g < len)
        curr->info->longest_g = len;
    return(true);
}

static void    doublicate_info(t_arg *ls_list, t_dir *dir,
            t_arg **ls_list_ptr, t_arg *curr)
{
    curr->name = ft_strdup(dir->d_name);
    curr->way = (*ls_list_ptr)->way;
    curr->info = ls_list->info;
    if (statistic(curr) &&
        (!(find_hidden_fd(ls_list->info, curr->name))))
            *(curr->blocks) += (float)curr->buff->st_size / 512;
    else
        return ;
}

void    addition(t_arg *ls_list, t_dir *direct, t_arg **ls_list_ptr)
{
    t_arg   *curr;

    if ((*ls_list_ptr)->name)
    {
        if (!(curr = (t_arg*)malloc(sizeof(t_arg))))
            mal_error();
        (*ls_list_ptr)->next_arg = curr;
        curr->blocks = (*ls_list_ptr)->blocks;
        curr->way = (*ls_list_ptr)->way;
        *ls_list_ptr = (*ls_list_ptr)->next_arg;
    }
    else
    {
        curr = (*ls_list_ptr);
        free(curr->blocks);
        if (!(curr->blocks = (float*)malloc(sizeof(float))))
            mal_error();
    }
    doublicate_info(ls_list, direct, ls_list_ptr, curr);
}

void    begin_sorting(t_arg **arg_list)
{
  //add types of sorting by flags   
}

bool   ft_ls(t_ls *ls)
{
    DIR     *fd;
    t_dir   *direct;
    t_arg   *memorized;
    t_arg   *ls_list;

    if (!(fd = opendir(ls->direct)))
        return(direct_error());
    if (!(ls_list = (t_arg*)malloc(sizeof(t_arg))))
        return(init_error());
    memorized = ls_list;
    ls_list->way = find_way(ls_list->way, ls->direct);
    while ((direct = (t_dir *)readdir(fd)) || closedir(fd))
    {
        if(find_hidden_fd(ls, direct->d_name))
            continue ;
        ls_list->info = ls;
        addition(ls_list, direct, &ls_list);
        if (ls_list->next_arg)
            ls_list = ls_list->next_arg;
    }
    begin_sorting(&memorized);
    return(true);
}

int main(int argc, char **argv)
{
    t_ls    *ls;

    if (!(ls = (t_ls *)malloc(sizeof(t_ls))))
        mal_error();
    get_arguments(ls, argc, argv);
    if (ft_ls(ls))
        return (1);
    else
        return (0);
}