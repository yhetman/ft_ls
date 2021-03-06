/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:55:18 by yhetman           #+#    #+#             */
/*   Updated: 2019/04/14 20:22:56 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

# include "../libft/includes/libft.h"
# include "ft_ls.h"

typedef struct	dirent		t_dir;
/*
	{
		ino_t	d_ino		-	file serial number
		char	*d_name		-	name of entry  
	}
*/

//  http://man7.org/linux/man-pages/man2/stat.2.html

typedef struct	stat		t_stat;
/*
	{
		dev_t		st_dev;			-		ID of device containing file 
		ino_t		st_ino;			-		Inode number 
		mode_t		st_mode;		-		File type and mode 
		nlink_t		st_nlink;		-		Number of hard links 
		uid_t		st_uid;			-		User ID of owner 
		gid_t		st_gid;			-		Group ID of owner 
		dev_t		st_rdev;		-		Device ID (if special file) 
		off_t		st_size;		-		Total size, in bytes 
		blksize_t	st_blksize;		-		Block size for filesystem I/O 
		blkcnt_t	st_blocks;		-		Number of 512B blocks allocated
		t_timedif	st_atimespec;			Time of last access 
		t_timedif	st_mtimespec;			Time of last modification 
		t_timedif	st_ctimespec;			Time of last status change 

		#define st_atime st_atim.tv_sec		Backward compatibility 
		#define st_mtime st_mtim.tv_sec
		#define st_ctime st_ctim.tv_sec
	}
*/
typedef struct	timespec	t_timedif;
/*
	{
		st_atim		-	time of last access
		st_mtim		-	time of last modification
		st_ctim		-	time of last status change
	}
*/
typedef struct	passwd		t_passwd;
/*
	{
		char	*pw_name;		-	username
		char	*pw_passwd;		-	user password
		uid_t	pw_uid;			-	user ID
		gid_t	pw_gid;			-	group ID
		char	*pw_gecos;		-	user information
		char	*pw_dir;		-	home directory
		char	*pw_shell;		-	shell program
	}
*/
typedef struct	group		t_group;
/*
	{
		char	*gr_name			The name of the group. 
		gid_t	gr_gid				Numerical group ID. 
		char	**gr_mem			Pointer to a null-terminated array of character 
									pointers to member names.
	}
*/
typedef struct	s_time
{
	char		*day;
	char		*month;
	char		*year;
}				t_time;

typedef struct	s_flags
{
/************	MANDATORY PART  *******************/
	bool		l;	//	(-l)	list in long format;
	bool		r;	//	(-r)	reverse the order of the sort to get reverse lexicographical 							order;
	bool		rr;	//	(-R)	recursively list subdirectories encountered;
	bool		a;	//	(-a)	include directory entries whose names begin with . ;
	bool		t;	//	(-t)	sort by time modified (most recently - first) befor lexic-sort;

/************	END OF MANDATORY PART  ************/

	bool		g;	//	(-g)	available for compatibility with POSIX; it is used to display 							the group name in the long format output;
	bool		c;	//	(-c)	use time when file status was last chenged;
	bool		aa;	//	(-A)	list all entries except for . and ..  ;
	bool		ll;	//	(-L)	follow all symbolic links to final target and list the file 							or directory;
	bool		cc;	//	(-C)	multi-column output;
	bool		gg;	//	(-G)	default coloring of the output;
	bool		u;	//	(-u)	use time of last access, instead of last modification of the 							file;
	bool		f;	//	(-f)	output is not sorted, this option turns on -a option;
	bool		d;	//	(-d)	directories are listed as plain files (not searched 									recursively);
}				t_flags;

typedef struct			s_ls
{
	t_flags				*flags;
	int					longest;
	int					longest_w;
	int					longest_g;
	char				*direct;
}						t_ls;

typedef struct			s_arg
{
	char				*name;
	char				*way;
	float				*blocks;
	t_stat				*stbuf;
	t_ls				*info;
	struct s_arg		*direct;
	struct s_arg		*next_arg;
}						t_arg;

#endif