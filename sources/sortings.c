/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:36:03 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/10 22:38:49 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	begin_sorting(t_arg **arg_list)
{
	if ((*arg_list)->info->flags.r)
		reverse_order(arg_list);
	if ((*arg_list)->info->flags.l)
		lexic_sorting(arg_list);
	if ((*arg_list)->info->flags.t)
		time_sorting(arg_list);
	if	((*arg_list)->info->flags.c)
		last_change_sorting(arg_list);
	if ((*arg_list)->info->flags.u)
		last_access_sorting(arg_list);
}