/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 05:34:57 by allauren          #+#    #+#             */
/*   Updated: 2018/04/07 09:22:07 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** handle signals, there is actually 32 signals defines in the man, 
** to be sure, i decided to activate 32 of them (the numbers are in man signal)
** and apply the variables to my program only when needed.
** did not use global but function that could hold the list i Created with arguments
*/

void	exiterror(void)
{
	if (ft_saveparam(0) == -1)
		ft_printf("error in reinit param shell\n");
	del_all_lst(get_elems(NULL)->lst);
	exit(-1);
}

void	handle_sign(int signal)
{
	if (signal == SIGWINCH)
		ft_printf("je change%d\n",signal);
	else if (signal == SIGCONT)
		ft_printf("read %d\n", signal);
	else if (signal == SIGTSTP)
		ft_printf("read %d\n", signal);
	else
		exiterror();
}

void	signals_init(void)
{
	int		i;

	i = 0;
	while (++i < 32)
		if (i != 11)
		signal(i, handle_sign);
}
