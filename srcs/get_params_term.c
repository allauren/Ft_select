/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params_term.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 07:08:58 by allauren          #+#    #+#             */
/*   Updated: 2018/04/07 13:53:30 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_saveparam(int t)
{
	static struct termios term;

	if (t)
	{
		if (tcgetattr(STDIN_FILENO, &term))
			return(-1);
	}
	else
	{
		if (tcsetattr(STDIN_FILENO, TCSANOW, &term))
			return (-1);
	}
	return(0);
}

void		get_wsize(t_env *env)
{
	if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &env->w))
		ft_printf("error in winsize\n");
	ft_printf("\n avant %d et %d\n", env->mlen, env->size);
	get_elems(env);
	isvalidsize(env);
	 ft_printf ("ici lines %d\n", env->w.ws_row);
	    ft_printf ("ici columns %d\n", env->w.ws_col);
}

