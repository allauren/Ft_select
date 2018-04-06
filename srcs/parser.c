/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 00:40:39 by allauren          #+#    #+#             */
/*   Updated: 2018/04/07 01:40:10 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			parseargs(t_env *env, int argc, char **argv)
{
	t_data	cnt;
	t_list	*new;

	while (++env->i < argc)
	{
		ft_bzero(&cnt, sizeof(t_data));
		cnt.name = ft_strdup(argv[env->i]);
		if (!(new = ft_lstnew(&cnt, sizeof(t_data))))
			return (-1);
		ft_lstadd(&env->lst, new);
	}
	while(new->next)
		new = new->next;
	((t_data*)(env->lst->content))->start = 1;
	new->next = env->lst;
	return (1);
}
