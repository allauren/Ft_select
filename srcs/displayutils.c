/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 12:03:37 by allauren          #+#    #+#             */
/*   Updated: 2018/04/09 18:12:27 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		divide(int x, int y)
{
	return(x / y + 7  +  x % y > 0);
}

int		isvalidsize(t_env *env)
{
	ft_printf ("ici lines %d et len %d\n", env->w.ws_row, env->mlen);
	ft_printf ("ici columns %d et size %d\n", env->w.ws_col, env->size);
//	ft_printf ("columns %d et %d et %d a depasser \n", env->size , divide(env->mlen, env->w.ws_col), env->w.ws_row);
//	ft_printf ("ligne %d et %d et %d a depasser \n", env->mlen , divide(env->size, env->w.ws_row), env->w.ws_col);
	if ((env->mlen * divide(env->size, env->w.ws_row)) > env->w.ws_col
			||((env->size * divide(env->mlen, env->w.ws_col)) > env->w.ws_row && ft_printf("c est lui")))
		return(ft_printf ("Je suis trop petit pour afficher ca moi :(\n"));
	return (0);
}
