/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params_term.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 07:08:58 by allauren          #+#    #+#             */
/*   Updated: 2018/04/07 08:22:41 by allauren         ###   ########.fr       */
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
		ft_printf("coucou:)");
		if (tcsetattr(STDIN_FILENO, TCSANOW, &term))
			return (-1);
	}
	return(0);
}
