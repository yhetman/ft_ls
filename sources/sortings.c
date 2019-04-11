/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:36:03 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/11 21:35:12 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_arg	*reverse_order(t_arg *arg_list)
{
	t_arg	*sorted;
	
	if (!(sorted = (t_arg*)malloc(sizeof(t_arg))))
		mal_error();
	else
	{
		sorted->next_arg = arg_list;
		while (arg_list && arg_list->next_arg)
		{
			if (ft_strcmp(arg_list->name, arg_list->next_arg->name) > 0)
			{
				swap_files(sorted, arg_list, arg_list->next_arg);
				arg_list = sorted->next_arg;
			}
			else
				arg_list = arg_list->next_arg;
		}
	}
	return (sorted->next_arg);
}

static t_arg	*lexic_sorting(t_arg *arg_list)
{
	t_arg	*sorted;
	
	if (!(sorted = (t_arg*)malloc(sizeof(t_arg))))
		mal_error();
	else
	{
		sorted->next_arg = arg_list;
		while (arg_list && arg_list->next_arg)
		{
			if (ft_strcmp(arg_list->name, arg_list->next_arg->name) < 0)
			{
				swap_files(sorted, arg_list, arg_list->next_arg);
				arg_list = sorted->next_arg;
			}
			else
				arg_list = arg_list->next_arg;
		}
	}
	return (sorted->next_arg);
}

static t_arg	*time_sorting(t_arg *arg_list)
{
	t_arg	*sorted;
	
	if (!(sorted = (t_arg*)malloc(sizeof(t_arg))))
		mal_error();
	else
	{
		sorted->next_arg = arg_list;
		while (arg_list && arg_list->next_arg)
		{
			if (arg_list->buff->st_mtimespec.tv_nsec
			> arg_list->next_arg->buff->st_mtimespec.tv_nsec)
			{
				swap_files(sorted, arg_list, arg_list->next_arg);
				arg_list = sorted->next_arg;
			}
			else
				arg_list = arg_list->next_arg;
		}
	}
	return (sorted->next_arg);
}

static t_arg	*last_change_sorting(t_arg *arg_list)
{
	t_arg	*sorted;
	
	if (!(sorted = (t_arg*)malloc(sizeof(t_arg))))
		mal_error();
	else
	{
		sorted->next_arg = arg_list;
		while (arg_list && arg_list->next_arg)
		{
			if (arg_list->buff->st_ctimespec.tv_nsec
			> arg_list->next_arg->buff->st_ctimespec.tv_nsec)
			{
				swap_files(sorted, arg_list, arg_list->next_arg);
				arg_list = sorted->next_arg;
			}
			else
				arg_list = arg_list->next_arg;
		}
	}
	return (sorted->next_arg);
}


static t_arg	*last_access_sorting(t_arg *arg_list)
{
	t_arg	*sorted;
	
	if (!(sorted = (t_arg*)malloc(sizeof(t_arg))))
		mal_error();
	else
	{
		sorted->next_arg = arg_list;
		while (arg_list && arg_list->next_arg)
		{
			if (arg_list->buff->st_atimespec.tv_nsec
			> arg_list->next_arg->buff->st_atimespec.tv_nsec)
			{
				swap_files(sorted, arg_list, arg_list->next_arg);
				arg_list = sorted->next_arg;
			}
			else
				arg_list = arg_list->next_arg;
		}
	}
	return (sorted->next_arg);
}

void	begin_sorting(t_arg **arg_list)
{
	if ((*arg_list)->info->flags.r)
		*arg_list = reverse_order(*arg_list);
	if ((*arg_list)->info->flags.l)
		*arg_list = lexic_sorting(*arg_list);
	if ((*arg_list)->info->flags.t)
		*arg_list = time_sorting(*arg_list);
	if ((*arg_list)->info->flags.c)
		*arg_list = last_change_sorting(*arg_list);
	if ((*arg_list)->info->flags.u)
		*arg_list = last_access_sorting(*arg_list);
}