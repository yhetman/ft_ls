/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:36:03 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/12 21:54:06 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_arg	*reverse_order(t_arg *sorted, t_arg *arg_list)
{
	sorted->next_arg = arg_list;
	while (arg_list && arg_list->next_arg)
		((ft_strcmp(arg_list->name, arg_list->next_arg->name) > 0) 
			? swap_files(sorted, arg_list, arg_list->next_arg)
			: (arg_list = arg_list->next_arg));
	return (sorted->next_arg);
}

t_arg	*lexic_sorting(t_arg *sorted, t_arg *arg_list)
{
	sorted->next_arg = arg_list;
	while (arg_list && arg_list->next_arg)
		((ft_strcmp(arg_list->name, arg_list->next_arg->name) < 0) 
			? swap_files(sorted, arg_list, arg_list->next_arg)
			: (arg_list = arg_list->next_arg));
	return (sorted->next_arg);
}

t_arg	*time_sorting(t_arg *sorted, t_arg *arg_list)
{
	sorted->next_arg = arg_list;
	while (arg_list && arg_list->next_arg)
		((arg_list->buff->st_mtimespec.tv_nsec
		> arg_list->next_arg->buff->st_mtimespec.tv_nsec)
			? swap_files(sorted, arg_list, arg_list->next_arg)
			: (arg_list = arg_list->next_arg));
	return (sorted->next_arg);
}

t_arg	*last_change_sorting(t_arg *sorted, t_arg *arg_list)
{
	sorted->next_arg = arg_list;
	while (arg_list && arg_list->next_arg)
		((arg_list->buff->st_ctimespec.tv_nsec
		> arg_list->next_arg->buff->st_ctimespec.tv_nsec)
			? swap_files(sorted, arg_list, arg_list->next_arg)
			: (arg_list = arg_list->next_arg));
	return (sorted->next_arg);
}


t_arg	*last_access_sorting(t_arg *sorted, t_arg *arg_list)
{
	sorted->next_arg = arg_list;
	while (arg_list && arg_list->next_arg)
		((arg_list->buff->st_atimespec.tv_nsec
		> arg_list->next_arg->buff->st_atimespec.tv_nsec)
			? swap_files(sorted, arg_list, arg_list->next_arg)
			: (arg_list = arg_list->next_arg));
	return (sorted->next_arg);
}

void			begin_sorting(t_arg **arg_list)
{
	//t_arg	*sorted;

	//if (!(sorted = (t_arg*)malloc(sizeof(t_arg))))
	//	mal_error();
	//else
	//{
		ft_printf("HERE IT IS");
		if ((*arg_list)->info->flags.r)
			ft_printf(" NO SHIT WITH r-flag\n");//*arg_list = reverse_order(sorted, *arg_list);
		else if ((*arg_list)->info->flags.t)
			ft_printf(" NO SHIT WITH t-flag\n");//*arg_list = time_sorting(sorted, *arg_list);
		else if ((*arg_list)->info->flags.c)
			ft_printf(" NO SHIT WITH c-flag\n");//*arg_list = last_change_sorting(sorted, *arg_list);
		else if ((*arg_list)->info->flags.u)
			ft_printf(" NO SHIT WITH u-flag\n");//*arg_list = last_access_sorting(sorted, *arg_list);
		else
			ft_printf(" NO SHIT WITH l-flag\n");//*arg_list = lexic_sorting(sorted, *arg_list);
	//}
	//generate_output(arg_list);
}