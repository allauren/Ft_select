/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 00:40:39 by allauren          #+#    #+#             */
/*   Updated: 2018/04/09 15:53:49 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			parseargs(t_env *env, int argc, char **argv)
{
	t_data	cnt;
	t_node	*new;

	while (++env->i < argc)
	{
		ft_bzero(&cnt, sizeof(t_data));
		cnt.name = ft_strdup(argv[env->i]);
		cnt.len = ft_strlen(argv[env->i]);
		env->mlen = cnt.len > env->mlen ? cnt.len : env->mlen;
		env->size++;
		ft_doublelink_addn(&env->lst, &cnt, sizeof(t_data));
	}
	new = env->lst;
	while(new->next)
		new = new->next;
	((t_data*)(env->lst->content))->start = 1;
	((t_data*)(env->lst->content))->cursor = 1;
	new->next = env->lst;
	env->lst->prev = new;
	return (1);
}
