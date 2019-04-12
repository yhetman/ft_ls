/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:00:17 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/12 21:39:27 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	free_ls(t_ls **ls)
{
	if (ls == NULL)
		return ;
	else
		ft_memdel((void**)ls);
}

char	*find_way(char *way, char *dir)
{
	if ((way && !*way) || !way )
	{
		way = ft_strdup(dir);
		return (way);
	}
	else
	{
		way = ft_strjoin(way, "/");
		way = ft_strjoin(way, dir);
		return (way);
	}
}

bool	find_hidden_fd(t_ls *ls, char *line)
{
	if (ls->flags.a)
		return(false);
	else if (*line == '.')
		return(true);
	else
		return(false);
}

bool	statistic(t_arg *curr)
{
	int			len;
	t_stat		*buff;
	t_passwd	*p;
	t_group		*grp;

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
	ft_printf(" NO SHIT IN statistic\n");
	return(true);
}

void	doublicate_info(t_arg *ls_list, t_dir *dir,
			t_arg **ls_list_ptr, t_arg *curr)
{
	curr->name = ft_strdup(dir->d_name);
	curr->way = (*ls_list_ptr)->way;
	curr->info = ls_list->info;
	if (statistic(curr) &&
		(!(find_hidden_fd(ls_list->info, curr->name))))
			{*(curr->blocks) += (float)curr->buff->st_size / 512;
			ft_printf(" NO SHIT IN doublicate_info\n");}
	else
		return ;
}

void	addition(t_arg *ls_list, t_dir *direct, t_arg **ls_list_ptr)
{
	t_arg	*curr;

	if ((*ls_list_ptr)->name)
	{
		if (!(curr = (t_arg*)malloc(sizeof(t_arg))))
			mal_error();
		(*ls_list_ptr)->next_arg = curr;
		curr->blocks = (*ls_list_ptr)->blocks;
		curr->way = (*ls_list_ptr)->way;
		*ls_list_ptr = (*ls_list_ptr)->next_arg;
		ft_printf(" NO SHIT IN addition\n");
	}
	else
	{
		curr = (*ls_list_ptr);
		free(curr->blocks);
		if (!(curr->blocks = (float*)malloc(sizeof(float))))
			mal_error();
		ft_printf(" NO SHIT IN addition\n");
	}
	doublicate_info(ls_list, direct, ls_list_ptr, curr);
}

bool	in(t_arg **ls_list)
{
	if (ls_list)
	{
		*ls_list = (t_arg *)ft_memalloc(sizeof(t_arg));
		if (!ls_list)
		{
			mal_error();
			return (false);
		}
		return (true);
	}
	else
		return (false);
}

bool	ft_ls(t_ls *ls)
{
	DIR		*fd;
	t_dir	*direct;
	t_arg	*memorized;
	t_arg	*ls_list;

	if (!(fd = opendir(ls->direct)))
		return (direct_error());
	if (!in(&ls_list))
		return (false);
	memorized = ls_list;
	//if (ls->flags.t) {ft_printf("LOOK DOWN!\n");}
	ls_list->way = find_way(ls_list->way, ls->direct);
	ft_printf("%s\n%s", ls_list->way, ls->direct);
	while ((direct = (t_dir *)readdir(fd)) || closedir(fd))
	{	//if (ls->flags.t) {ft_printf("LOOK DOWN!!\n");}
		if(find_hidden_fd(ls, direct->d_name))
			continue ;
		ls_list->info = ls;
		//if (ls->flags.t) {ft_printf(" NO SHIT IN find_hidden_fd\n");}
		addition(ls_list, direct, &ls_list);
		if (ls_list->next_arg)
			ls_list = ls_list->next_arg;
	}
	begin_sorting(&memorized);
	return(true);
}

t_ls	get_arguments(t_ls *ls, int argc, char **argv)
{
	int	x;

	x = 1;
	while (x < argc)
	{
		if (*(argv[x]) == '-')
			get_flags(argv[x], &ls);
		else
			break ;
		x++;
	}
	if (x < argc)
		ls->direct = ft_strdup(argv[x]);
	else
		ls->direct = ft_strdup("./");
	return(*ls);
}

int		main(int argc, char **argv)
{
	t_ls	ls;
	
	ls = get_arguments(&ls, argc, argv);
	if (ft_ls(&ls))
		return (1);
	else
		return (0);
}