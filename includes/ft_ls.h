/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:02:40 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/16 21:08:34 by yhetman          ###   ########.fr       */
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
bool	direct_error(void);
void	link_error(void);

/******		sortings.c		******/
void	begin_sorting(t_arg **arg_list, t_flags **flags); // -r , -l , -t , -c , -u
void	generate_output(t_arg *arg_list);

/******	dir.c			******/
void	get_dir(t_arg *arg_list);

/******	ft_ls.c			******/
char	*find_way(char *way, char *dir);
bool	find_hidden_fd(t_ls *ls, char *line);

/******	flags.c			******/
void	get_flags(char *str, t_ls **ls);

/******	swap_files.c	******/
void	swap_files(t_arg *b, t_arg *f, t_arg *s);

/******	adding.c		******/
bool	adding(t_arg *ls_list, t_dir *direct, t_arg **ls_list_ptr);

#endif
