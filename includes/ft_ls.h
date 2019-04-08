/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:37:00 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/08 19:55:16 by yhetman          ###   ########.fr       */
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

typedef struct  s_ls
{
    /*data */
}               t_ls;

typedef struct  s_flags
{
/************   MANDATORY PART  *******************/
    int         l;  //  (-l)    list in long format;
    int         r;  //  (-r)    reverse the order of the sort to get reverse lexicographical order;
    int         rr; //  (-R)    recursively list subdirectories encountered;
    int         a;  //  (-a)    include directory entries whose names begin with . ;
    int         t;  //  (-t)    sort by time modified (most recently - first) befor lexic-sort;

/************   END OF MANDATORY PART  ************/

    int         g;  //  (-g)    available for compatibility with POSIX; it is used to display the group name in the long format output;
    int         c;  //  (-c)    use time whem file status was last chenged;
    int         aa; //  (-A)    list all entries except for . and ..  ;
    int         ll; //  (-L)    follow all symbolic links to final target and list the file or directory;
    int         cc; //  (-C)    multi-column output;
    int         gg; //  (-G)    default coloring of the output;
    int         u;  //  (-u)    use time of last access, instead of last modification of the file;
    int         f;  //  (-f)    output is not sorted, this option turns on -a option;
    int         d;  //  (-d)    directories are listed as plain files (not searched recursively);
}               t_flags;

#endif