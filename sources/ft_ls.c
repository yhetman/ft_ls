/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:39:21 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/09 15:21:48 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void     free_ls(t_ls **ls)
{
    if (ls == NULL)
        return ;
    else
        ft_memdel((void**)ls);
}
static void     print_help(void)
{
    ft_printf("\t%{yellow}-l%{eoc}\t%{green}to list in long format;%{eoc}\n\n");
    ft_printf("\t%{yellow}-r%{eoc}\t%{green}to reverse the order of the ");
    ft_printf("sort to get reverse lexicographical order;%{eoc}\n\n");
    ft_printf("\t%{yellow}-R%{eoc}\t%{green}list subdirectories encountered recursively;%{eoc}\n\n");
    ft_printf("\t%{yellow}-a%{eoc}\t%{green}include directory entries whose names begin with . ;%{eoc}\n\n");
    ft_printf("\t%{yellow}-t%{eoc}\t%{green}sort by time modified (most recently - first) befor lexic-sort;%{eoc}\n\n");
    ft_printf("\t%{yellow}-g%{eoc}\t%{green}available for compatibility with POSIX;");
    ft_printf("it is used to display the group name in the long format output;%{eoc}\n\n");
    ft_printf("\t%{yellow}-c%{eoc}\t%{green}use time when file status was last chenged;%{eoc}\n\n");

}
static void     flag_error(void)
{
    ft_printf("\t%{red}Error: Invalid flag!\n Try '--help' to check available flags%{red}\n");
    exit(EXIT_FAILURE);
}

static bool     get_bonus_flags(char * str, int x, t_ls *ls)
{
    if (str[x] == 'l')
        return(ls->flags.l = true);
    if (str[x] == 'r')
        return(ls->flags.r = true);
    if (str[x] == 'R')
        return(ls->flags.rr = true);
    if (str[x] == 'a')
        return(ls->flags.a = true);
    if (str[x] == 't')
        return(ls->flags.t = true);
    if (str[x] == 'g')
        return(ls->flags.g = true);
    if (str[x] == 'c')
        return(ls->flags.c = true);
    if (str[x] == 'A')
        return(ls->flags.aa = true);
    if (str[x] == 'L')
        return(ls->flags.ll = true);
    if (str[x] == 'C')
        return(ls->flags.cc = true);
    if (str[x] == 'G')
        return(ls->flags.gg = true);
    if (str[x] == 'u')
        return(ls->flags.u = true);
    if (str[x] == 'f')
        return((ls->flags.f = true) && (ls->flags.a = true));
    if (str[x] == 'd')
        return(ls->flags.d = true);
    else
        return(false);   
}

static bool     get_flags(char *str, t_ls *ls)
{
    int x;

    x = 0;
    if (ft_strstr(str, "--help"))
    {
        print_help();
        return(false);
    }
    if(str[x] == '-')
    {
        while (str[++x])
        {
            if (!get_bonus_flags(str, x, ls))
                flag_error();   
        }
        return(true);
    }
    return(false);
}

static t_ls     *get_arguments(t_ls *ls, int argc, char **argv)
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
        x++;
    }
    return(ls);
}

int main(int argc, char **argv)
{
    t_ls    *ls;

    ls = (t_ls *)malloc(sizeof(t_ls));
    ls = get_arguments(ls, argc, argv);

    return (0);
}