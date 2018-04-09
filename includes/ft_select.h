/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 22:47:52 by allauren          #+#    #+#             */
/*   Updated: 2018/04/09 16:53:04 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <term.h>
# include <curses.h>
# include <sys/ioctl.h>
# define L_ARROW 68
# define T_ARROW 65
# define B_ARROW 66
# define R_ARROW 67

typedef struct		s_env
{
	t_node			*lst;
	int				i;
	char			*name;
	int				size;
	int				mlen;
	struct winsize	w;
	int				fd;
}					t_env;

typedef struct		s_data
{
	char	*name;
	int		start;
	int		cursor;
	int		select;
	int		len;
}					t_data;

/*
** error functions
*/

int		ft_usage(void);
int		ft_print_malloc(void);
int			initterm(void);
void	get_cursornext(t_env *env);
void	get_cursorprev(t_env *env);

/*
**  parsing functions
*/

void		set_caps(char *str);
int			open_tty(t_env *env);
int			parseargs(t_env *env, int argc, char **argv);
void		signals_init(void);
t_env		*get_elems(t_env *env);
int			ft_saveparam(int t);
void		get_wsize(t_env *env);
int		isvalidsize(t_env *env);
void	isselect(t_env *env);
void	exiterror(void);

/*
** free functions
*/
void	deleleme(t_env *env);
void		deldata(t_data *data);
void		del_lst(t_node *lst);
void		del_all_lst(t_node *lst);
void		print_all_lst(t_node *lst);

#endif
