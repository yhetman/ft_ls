/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 16:01:40 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/18 17:59:29 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static bool	statistic(t_arg *curr)
{
	t_stat		*stbuf;
	t_passwd	*p;
	t_group		*grp;

	if (!(stbuf = (t_stat*)malloc(sizeof(t_stat)))
		|| !(p = (t_passwd*)malloc(sizeof(t_passwd)))
		|| !(grp = (t_group*)malloc(sizeof(t_group))))
		mal_error();
	else
	{
		if (lstat(find_way(curr->way, curr->name), stbuf) < 0)
			link_error();
		curr->stbuf = stbuf;
		p = getpwuid(curr->stbuf->st_uid);
		if (curr->info->longest < (int)ft_nbrlen(curr->stbuf->st_size))
			curr->info->longest = (int)ft_nbrlen(curr->stbuf->st_size);
		if (curr->info->longest_w < (int)LEN(p->pw_name))
			curr->info->longest_w = (int)LEN(p->pw_name);
		grp = getgrgid(curr->stbuf->st_gid);
		if (curr->info->longest_g < (int)LEN(grp->gr_name))
			curr->info->longest_g = (int)LEN(grp->gr_name);
		return (true);
	}
	return (false);
}

static bool	doublicate_info(t_arg *ls_list, t_dir *dir,
			t_arg **ls_list_ptr, t_arg *curr)
{
	curr->name = ft_strdup(dir->d_name);
	curr->way = (*ls_list_ptr)->way;
	curr->info = ls_list->info;
	if (statistic(curr) &&
		(!(find_hidden_fd(ls_list->info, curr->name))))
		{
			*(curr->blocks) += (float)curr->stbuf->st_size / 512;
			return (true);
		}
	else
		return (false);
}

bool	adding(t_arg *ls_list, t_dir *direct, t_arg **ls_list_ptr)
{
	t_arg	*curr;

	if ((*ls_list_ptr)->name)
	{
		if (!(curr = (t_arg*)malloc(sizeof(t_arg))))
			mal_error();
		ft_bzero(curr, sizeof(t_arg));
		(*ls_list_ptr)->next_arg = curr;
		curr->blocks = (*ls_list_ptr)->blocks;
		curr->way = (*ls_list_ptr)->way;
		*ls_list_ptr = (*ls_list_ptr)->next_arg;
	}
	else
	{
		curr = (*ls_list_ptr);
		free(curr->blocks);
		if (!(curr->blocks = (float *)malloc(sizeof(float))))
			mal_error();
		ft_bzero(curr->blocks, sizeof(float));
	}
	return (doublicate_info(ls_list, direct, ls_list_ptr, curr));
}
