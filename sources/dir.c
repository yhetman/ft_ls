/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 20:37:06 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/14 20:38:23 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


static void	create_dir(t_arg *arg_list)
{
	t_arg	*new_arg;

	if (!(new_arg = (t_arg *)ft_memalloc(sizeof(t_arg))))
		mal_error();
	new_arg->info = arg_list->info;
	new_arg->way = find_way(arg_list->way, arg_list->name);
	arg_list->direct = new_arg;
}

static void	recursive_dir(t_arg *arg_list)
{
	 DIR		*fd;
	t_dir	*direct;
	t_arg	*current;

	current = arg_list->direct;
	if (!(fd = opendir(current->way)))
		direct_error();
	while ((direct = (t_dir*)readdir(fd)))
	{
		adding(arg_list, direct, &current);
		if (current->next_arg)
			current = current->next_arg;
	}
	closedir(fd);
}

void		get_dir(t_arg *arg_list)
{
	while (arg_list)
	{
		if (ft_strcmp(arg_list->name, ".")
			&& ft_strcmp(arg_list->name, "..")
			&& S_ISDIR(arg_list->stbuf->st_mode))
		{
			create_dir(arg_list);
			recursive_dir(arg_list);
			begin_sorting(&(arg_list->direct),
			&(arg_list->info->flags));
			ft_printf("\n%s/%s:\n", arg_list->way, arg_list->name);
			generate_output(arg_list->direct);
			get_dir(arg_list->direct);
		}
		arg_list = arg_list->next_arg;
	}
}
