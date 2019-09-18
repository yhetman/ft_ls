/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:36:03 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/18 18:02:05 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_arg	*reverse_order(t_arg *arg_list)
{
	t_arg	*sorted;

	if (!(sorted = (t_arg*)malloc(sizeof(t_arg))))
		mal_error();
	sorted->next_arg = arg_list;
	while (arg_list && arg_list->next_arg)
		((ft_strcmp(arg_list->name, arg_list->next_arg->name) > 0) 
			? swap_files(sorted, arg_list, arg_list->next_arg)
			: (arg_list = arg_list->next_arg));
	return (sorted->next_arg);
}

t_arg	*lexic_sorting(t_arg *arg_list)
{
	t_arg	*sorted;

	if (!(sorted = (t_arg*)malloc(sizeof(t_arg))))
		mal_error();
	sorted->next_arg = arg_list;
		while (arg_list && arg_list->next_arg)
			((ft_strcmp(arg_list->name, arg_list->next_arg->name) < 0) 
				? swap_files(sorted, arg_list, arg_list->next_arg)
				: (arg_list = arg_list->next_arg));
	return (sorted->next_arg);
}

t_arg	*time_sorting(t_arg *arg_list)
{
	t_arg	*sorted;

	if (!(sorted = (t_arg*)malloc(sizeof(t_arg))))
		mal_error();
	sorted->next_arg = arg_list;
	while (arg_list && arg_list->next_arg)
		((arg_list->stbuf->st_mtimespec.tv_nsec
		> arg_list->next_arg->stbuf->st_mtimespec.tv_nsec)
			? swap_files(sorted, arg_list, arg_list->next_arg)
			: (arg_list = arg_list->next_arg));
	return (sorted->next_arg);
}

t_arg	*last_change_sorting(t_arg *arg_list)
{
	t_arg	*sorted;

	if (!(sorted = (t_arg*)malloc(sizeof(t_arg))))
		mal_error();
	sorted->next_arg = arg_list;
	while (arg_list && arg_list->next_arg)
		((arg_list->stbuf->st_ctimespec.tv_nsec
		> arg_list->next_arg->stbuf->st_ctimespec.tv_nsec)
			? swap_files(sorted, arg_list, arg_list->next_arg)
			: (arg_list = arg_list->next_arg));
	return (sorted->next_arg);
}


t_arg	*last_access_sorting(t_arg *arg_list)
{
	t_arg	*sorted;

	if (!(sorted = (t_arg*)malloc(sizeof(t_arg))))
		mal_error();
	sorted->next_arg = arg_list;
	while (arg_list && arg_list->next_arg)
		((arg_list->stbuf->st_atimespec.tv_nsec
		> arg_list->next_arg->stbuf->st_atimespec.tv_nsec)
			? swap_files(sorted, arg_list, arg_list->next_arg)
			: (arg_list = arg_list->next_arg));
	return (sorted->next_arg);
}

void		generate_output(t_arg *arg_list)
{
	//t_timedif	*t;
	//t_group		*group;
	//t_passwd	*pass;

	ft_printf("total %d/n", 5); //try
	while(arg_list)
	{
		ft_printf("%s/n", arg_list->name);
		arg_list = arg_list->next_arg;
	}
}

void		begin_sorting(t_arg **arg_list, t_flags **flags)
{
	if (!(*flags))
		return;
	ft_printf("total %d/n", 1);
	if ((*flags)->r == true)
		*arg_list = reverse_order(*arg_list);
	else if ((*flags)->t == true)
		*arg_list = time_sorting(*arg_list);
	else if ((*flags)->c == true)
		*arg_list = last_change_sorting(*arg_list);
	else if ((*flags)->u == true)
		*arg_list = last_access_sorting(*arg_list);
	else
		*arg_list = lexic_sorting(*arg_list);
	generate_output(*arg_list);
}
