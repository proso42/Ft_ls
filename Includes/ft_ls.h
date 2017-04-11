/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:30:24 by proso             #+#    #+#             */
/*   Updated: 2017/03/31 17:29:40 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include "ft_printf.h"
# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <sys/ioctl.h>
# include <sys/xattr.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>

typedef struct			s_option
{
	int					l;
	int					rr;
	int					r;
	int					s;
	int					a;
	int					t;
	int					m;
	int					f;
	int					one;
	char				*str_option;
}						t_option;

typedef struct			s_file_list
{
	char				*str;
	int					size;
	struct s_file_list	*next;
}						t_file_list;

typedef struct			s_stock
{
	int					nb_elem;
	int					inc;
	int					j;
	int					i;
	int					index;
}						t_stock;

typedef struct			s_info
{
	t_file_list			*perm_list;
	t_file_list			*link_list;
	t_file_list			*loggin_list;
	t_file_list			*grp_list;
	t_file_list			*weight_list;
	t_file_list			*date_list;
	int					sx_link;
	int					sx_loggin;
	int					sx_grp;
	int					sx_weight;
	unsigned long		total;
	struct stat			buf;
	struct passwd		*pw;
	struct group		*gr;
}						t_info;

int						ft_ls(struct dirent *data, DIR *dirp,
						t_option *option, char *path);
int						find_option(t_option *option, char **av);
int						get_width_win(void);
int						get_size_max(t_file_list *begin_list);
void					ft_push_back(t_file_list **begin_list, char *elem);
void					ft_reverse_list(t_file_list **begin_list);
void					choice_print(char *path, t_file_list *name_list,
													t_option *option);
void					ft_print_list_m(t_file_list *begin_list);
void					ft_print_list(t_file_list *begin_list);
void					ft_print_list_l(t_file_list *begin_list, char *path,
																	int i);
void					ft_print_list_1(t_file_list *begin_list);
void					ft_print_arg(t_file_list *arg_list, t_option *option);
void					ft_remove_list(t_file_list **begin_list);
void					ft_remove_struct(t_info **info);
void					re_init_size(t_file_list *begin_list);
void					sort_by_time(t_file_list **begin_list);
void					sort_by_ascii(t_file_list **begin_list);
void					sort_by_size(t_file_list **begin_list);
void					sort_in_col(t_file_list **begin_list);
void					fill_list_l(t_file_list *cur, char *path, char *tmp,
															t_info *info);
char					*get_weight(struct stat buf);
char					*get_date(struct stat buf);
char					*get_perm(struct stat buf, char *str, char *path);
char					*get_elem(t_file_list *begin_list, int i);
char					get_acl(char *str, char *path);
t_file_list				*get_p_elem(t_file_list *begin_list, int i);
t_file_list				*ft_dup_list(t_file_list *begin_list);
t_file_list				*get_list_arg(int ac, char **av, t_option *option);
t_info					*get_list_info(t_file_list *begin_list, char *path);

#endif
