/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 22:47:52 by allauren          #+#    #+#             */
/*   Updated: 2018/04/07 10:05:39 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <term.h>
# include <curses.h>
# include <sys/ioctl.h>

typedef struct		s_env
{
	t_list			*lst;
	int				i;
	char			*name;
	struct winsize	w;
}					t_env;

typedef struct		s_data
{
	char	*name;
	int		start;
}					t_data;

/*
** error functions
*/

int		ft_usage(void);
int		ft_print_malloc(void);

/*
**  parsing functions
*/

int			parseargs(t_env *env, int argc, char **argv);
void		signals_init(void);
t_env		*get_elems(t_env *env);
int			ft_saveparam(int t);
void		get_wsize(t_env *env);
	

/*
** free functions
*/
void		deldata(t_data *data);
void		del_lst(t_list *lst);
void		del_all_lst(t_list *lst);
void		print_all_lst(t_list *lst);

#endif
