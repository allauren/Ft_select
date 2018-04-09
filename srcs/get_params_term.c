/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params_term.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 07:08:58 by allauren          #+#    #+#             */
/*   Updated: 2018/04/09 09:55:41 by allauren         ###   ########.fr       */
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

int			initterm(void)
{
	struct termios term;

	if (tcgetattr(STDIN_FILENO, &term))
		return (-1);
	term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return(0);
}



int     voir_touche()
{
	char     buffer[3];

	while (1)
	{
		read(0, buffer, 3);
		if (buffer[0] == 27)
			printf("C'est une fleche !\n");
		else if (buffer[0] == 4)
		{
			printf("Ctlr+d, on quitte !\n");
			return (0);
		}
	}
	return (0);
}

void		get_wsize(t_env *env)
{
	if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &env->w))
		ft_printf("error in winsize\n");
	ft_printf("\n avant %d et %d\n", env->mlen, env->size);
	get_elems(env);
	if (!isvalidsize(env))
	{
		set_caps("cl");
		print_all_lst(env->lst);
		voir_touche();
	}
}

