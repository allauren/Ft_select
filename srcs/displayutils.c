/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 12:03:37 by allauren          #+#    #+#             */
/*   Updated: 2018/04/07 13:48:01 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		divide(int x, int y)
{
	return(x / y + 1);
}

void		isvalidsize(t_env *env)
{
	ft_printf ("erreur est la columns %d et %d et %d a depasser \n", env->size , divide(env->mlen, env->w.ws_row), env->w.ws_row);
	if ((env->mlen * divide(env->size, env->w.ws_col)) > env->w.ws_col
			||((env->size * divide(env->mlen, env->w.ws_row)) > env->w.ws_row && ft_printf("c est lui")))
		ft_printf ("Je suis trop petit pour afficher ca moi :(\n");
}
