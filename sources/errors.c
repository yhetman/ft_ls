/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:53:43 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/10 03:21:03 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void link_error(void)
{
	ft_printf("%\t{red}ERROR:\t Linkers failed! %s%{eoc}\n", strerror(errno));
	exit(EXIT_FAILURE);
}

void mal_error(void)
{
	ft_printf("%\t{red}ERROR:\t Malloc failed! %s%{eoc}\n", strerror(errno));
	exit(EXIT_FAILURE);
}

void flag_error(void)
{
    ft_printf("\t%{red}ERROR: Invalid flag!\n Try '--help' to check available flags%{red}\n");
    exit(EXIT_FAILURE);
}

int  direct_error()
{
    ft_printf("\t%{red}ERROR: %s%{eoc}\n", strerror(errno));
    return (-1);
}

int  init_error(void)
{
    ft_printf("\t%{red}ERROR: initialization failed!%{eoc}");
    return (-1);
}