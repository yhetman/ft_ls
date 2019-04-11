/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:02:40 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/11 21:35:54 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_LS_H
# define FT_LS_H

# include "structs.h"
# include "../libft/includes/libft.h"
# include <dirent.h>
/*
	int				closedir(DIR *);
	DIR				*opendir(const char *);
	struct dirent	*readdir(DIR *);
*/
# include <grp.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <sys/stat.h>
/*
	int				stat(const char *pathname, struct stat *statbuf);
	int				lstat(const char *pathname, struct stat *statbuf);
*/

# include <sys/acl.h>


/******		error.c			******/
void	mal_error(void);
void	flag_error(void);
int		direct_error(void);
int		init_error(void);
void	link_error(void);

/******		sortings.c		******/
void	begin_sorting(t_arg **arg_list); // -r , -l , -t , -c , -u


/******		flags.c			******/
bool	get_flags(char *str, t_ls *ls);

/******		swap_files.c	******/
void	swap_files(t_arg *b, t_arg *f, t_arg *s);
#endif