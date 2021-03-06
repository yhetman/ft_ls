/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:00:17 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/31 16:13:07 by yhetman          ###   ########.fr       */
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
	if (ls && ls->flags && ls->flags->a)
		return(false);
	else if (*line == '.')
		return(true);
	return (false);
}

static t_arg	*in(void)
{
	t_arg		*out;

	out = (t_arg *)malloc(sizeof(t_arg));
	ft_bzero(out, sizeof(t_arg));
	return (out);
}

int		ft_ls(t_ls *ls)
{
	DIR		*fd;
	t_dir	*direct;
	t_arg	*memorized;
	t_arg	*arg_list;

	if (!(fd = opendir(ls->direct)))
		return (direct_error());
	if (!(arg_list = in()))
		return (false);
	memorized = arg_list;
	arg_list->way = find_way(arg_list->way, ls->direct);
	while ((direct = (t_dir *)readdir(fd)) || closedir(fd))
	{
		if(find_hidden_fd(ls, direct->d_name))
			continue ;
		arg_list->info = ls;
		adding(arg_list, direct, &arg_list);
		if (arg_list->next_arg)
			arg_list = arg_list->next_arg;
	}
	begin_sorting(&memorized, &(memorized->info->flags));
	if (arg_list->info->flags && arg_list->info->flags->rr)
		get_dir(memorized);
	return (true);
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
	return (*ls);
}

int		main(int argc, char **argv)
{
	t_ls	ls;
	
	ls = get_arguments(&ls, argc, argv);
	return(ft_ls(&ls));
}
