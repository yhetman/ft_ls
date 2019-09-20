/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 01:31:44 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/18 18:54:51 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	print_help(void)
{
	ft_printf("\t%{yellow}-l%{eoc}\t%{green}to list in long format;%{eoc}\n\n");
	ft_printf("\t%{yellow}-r%{eoc}\t%{green}to reverse the order of the ");
	ft_printf("sort to get reverse lexicographical order;%{eoc}\n\n");
	ft_printf("\t%{yellow}-R%{eoc}\t%{green}list subdirectories encountered recursively;%{eoc}\n\n");
	ft_printf("\t%{yellow}-a%{eoc}\t%{green}include directory entries whose names begin with . ;%{eoc}\n\n");
	ft_printf("\t%{yellow}-t%{eoc}\t%{green}sort by time modified (most recently - first) befor lexic-sort;%{eoc}\n\n");
	ft_printf("\t%{yellow}-g%{eoc}\t%{green}available for compatibility with POSIX;");
	ft_printf("it is used to display the group name in the long format output;%{eoc}\n\n");
	ft_printf("\t%{yellow}-c%{eoc}\t%{green}use time when file status was last changed;%{eoc}\n\n");
	exit(EXIT_SUCCESS);
}

static void	define_flags(char str, t_flags **flags)
{
	if (!flags || !(*flags))
		return;
	if (str == 'l')
		(*flags)->l = true;
	else if (str == 'r')
		(*flags)->r = true;
	else if (str == 'R')
		(*flags)->rr = true;
	else if (str == 'a')
		(*flags)->a = true;
	else if (str == 't')
		(*flags)->t = true;
	else if (str == 'g')
		(*flags)->g = true;
	else if (str == 'c')
		(*flags)->c = true;
	else if (str == 'A')
		(*flags)->aa = true;
	else if (str == 'L')
		(*flags)->ll = true;
	else if (str == 'C')
		(*flags)->cc = true;
	else if (str == 'G')
		(*flags)->gg = true;
	else if (str == 'u')
		(*flags)->u = true;
	else if (str == 'f')
		((*flags)->f = true) && ((*flags)->a = true);
	else if (str == 'd')
		(*flags)->d = true;
	else
		return ;
}

void		get_flags(char *str, t_ls **ls)
{
	int x;

	x = -1;
	if (ft_strstr(str, "-help"))
		print_help();
	else if (*str == '-')
	{
		while (str[++x] != '\0')
			define_flags(str[x], &((*ls)->flags));
	}
	else
		flag_error();
}
