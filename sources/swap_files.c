/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:39:50 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/14 19:37:10 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	swap_files(t_arg *beg, t_arg *f, t_arg *s)
{
	t_arg	*t;

	if (!(t = (t_arg*)malloc(sizeof(t_arg))))
		mal_error();
	else
	{
		while (beg && beg->next_arg && beg->next_arg != f)
			beg = beg->next_arg;
		if (beg->next_arg == f)
		{
			t = s->next_arg;
			beg->next_arg = s;
			s->next_arg = f;
			f->next_arg = t;
			//ft_memdel((void**)t);
		}
		f = beg->next_arg;
	}
}