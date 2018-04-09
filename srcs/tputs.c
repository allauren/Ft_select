/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tputs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 05:41:44 by allauren          #+#    #+#             */
/*   Updated: 2018/04/09 06:07:13 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			open_tty(t_env *env)
{
	char *path;

	path = ttyname(STDIN_FILENO);
	if (!path)
		env->fd = STDOUT_FILENO;
	else if ((env->fd = open(path, O_WRONLY)) < 0)
	{
		ft_printf("impossible to open fd");
		ft_saveparam(0);
		return (-1);
	}
	return (0);
}

int			putcharftsel(int c)
{
	ft_putchar_fd(c, get_elems(NULL)->fd);
	return(0);
}
void		set_caps(char *str)
{
	tputs(tgoto(tgetstr("cl", NULL), 0, 0), 1, putcharftsel);
}
