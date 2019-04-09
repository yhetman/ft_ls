/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:37:00 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/09 17:26:14 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <sys/stat.h>
# include <sys/acl.h>

typedef struct  s_time
{
    char        *day;
    char        *month;
    char        *year;
}               t_time;

typedef struct  s_flags
{
/************   MANDATORY PART  *******************/
    bool         l;  //  (-l)    list in long format;
    bool         r;  //  (-r)    reverse the order of the sort to get reverse lexicographical order;
    bool         rr; //  (-R)    recursively list subdirectories encountered;
    bool         a;  //  (-a)    include directory entries whose names begin with . ;
    bool         t;  //  (-t)    sort by time modified (most recently - first) befor lexic-sort;

/************   END OF MANDATORY PART  ************/

   bool         g;  //  (-g)    available for compatibility with POSIX; it is used to display the group name in the long format output;
   bool         c;  //  (-c)    use time when file status was last chenged;
   bool         aa; //  (-A)    list all entries except for . and ..  ;
   bool         ll; //  (-L)    follow all symbolic links to final target and list the file or directory;
   bool         cc; //  (-C)    multi-column output;
   bool         gg; //  (-G)    default coloring of the output;
   bool         u;  //  (-u)    use time of last access, instead of last modification of the file;
   bool         f;  //  (-f)    output is not sorted, this option turns on -a option;
   bool         d;  //  (-d)    directories are listed as plain files (not searched recursively);
}               t_flags;

typedef struct  s_ls
{
    t_flags     flags;
    int         longest;
    int         longest_w;
    int         longets_g;
    char        *direct;
}               t_ls;

typedef struct  s_arguments
{
    char        *name;
    char        *path_way;
    float       *blocks;
    struct stat *buff;
    t_ls        *info;
    t_arg       *direct;
    t_arg       *next_arg;
}               t_arg;
#endif