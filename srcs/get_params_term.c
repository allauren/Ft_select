/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params_term.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 07:08:58 by allauren          #+#    #+#             */
/*   Updated: 2018/04/09 16:02:14 by allauren         ###   ########.fr       */
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
		set_caps("ti");
		set_caps("vi");
	}
	else
	{
		set_caps("te");
		set_caps("ve");
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

void	handle_arrow(int c)
{
	if (c == B_ARROW)
		get_cursornext(get_elems(NULL));
	else if (c == T_ARROW)
		get_cursorprev(get_elems(NULL));
	else if (c == R_ARROW)
		get_cursornext(get_elems(NULL));
	else if (c == L_ARROW)
		get_cursorprev(get_elems(NULL));
	else
		exit(-1);
}

int     voir_touche()
{
	char     buffer[3];
	int		ret;

	if (!(ret =  read(0, buffer, 4)))
		return (-1);
	buffer[ret] = 0;
	if (buffer[0] == 27 && buffer[1] == 91)
		handle_arrow(buffer[2]);
	if (buffer[0] == 32 && buffer[1] == 0)
		isselect(get_elems(NULL));
	if (buffer[0] == '\n' && !buffer[1])
		return(2);
	if (buffer[0] == 27 && !buffer[1])
		exiterror();
	return (0);
}

void		get_wsize(t_env *env)
{
	if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &env->w))
		ft_printf("error in winsize\n");
	ft_printf("\n avant %d et %d\n", env->mlen, env->size);
	get_elems(env);
	//	if (!isvalidsize(env))
	//	{
	while (1)
	{
		set_caps("cl");
		print_all_lst(env->lst);
		if (voir_touche() == 2)
			break;
	}
}
