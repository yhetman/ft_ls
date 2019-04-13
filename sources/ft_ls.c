/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:00:17 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/13 16:45:21 by yhetman          ###   ########.fr       */
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

int		ft_ls(t_ls *ls)
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
	ls_list->way = find_way(ls_list->way, ls->direct);
	while ((direct = (t_dir *)readdir(fd)) || closedir(fd))
	{
		if(find_hidden_fd(ls, direct->d_name))
			continue ;
		ls_list->info = ls;
		adding(ls_list, direct, &ls_list);
		if (ls_list->next_arg)
			ls_list = ls_list->next_arg;
	}
	if (begin_sorting(&memorized))
		return (true);
	else
		return (false);
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