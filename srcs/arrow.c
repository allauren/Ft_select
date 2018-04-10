/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:02:26 by allauren          #+#    #+#             */
/*   Updated: 2018/04/09 18:11:24 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	get_cursorprev(t_env *env)
{
	t_node	*cursor;
	t_data	*data;

	cursor = env->lst;
	while(!(data = cursor->content)->cursor)
		cursor = cursor->next;
	((t_data*)cursor->prev->content)->cursor = 1;
	((t_data*)cursor->content)->cursor = 0;
	get_elems(env);
}

void	get_cursornext(t_env *env)
{
	t_node	*cursor;
	t_data	*data;

	cursor = env->lst;
	while(!(data = cursor->content)->cursor)
		cursor = cursor->next;
	((t_data*)cursor->next->content)->cursor = 1;
	((t_data*)cursor->content)->cursor = 0;
	get_elems(env);
}

void	isselect(t_env *env)
{
	t_node	*cursor;
	t_node	*prev;
	t_data	*data;

	cursor = env->lst;
	while(!(data = cursor->content)->cursor)
		cursor = cursor->next;
	prev = cursor->next;
	((t_data*)prev->content)->cursor = 1;
	((t_data*)cursor->content)->cursor = 0;
	((t_data*)cursor->content)->select = ((t_data*)cursor->content)->select == 0;
	get_elems(env);
}

void			deleleme(t_env *env)
{
	t_node	*cursor;
	t_data	*data;

	cursor = env->lst;
	while(!(data = cursor->content)->cursor)
		cursor = cursor->next;
	cursor->prev->next = cursor->next;
	cursor->next->prev = cursor->prev;
	if (cursor == env->lst)
	{
		env->lst = env->lst->next;
		((t_data*)env->lst->content)->start = 1;
	}
	if (cursor == env->lst)
		exiterror();
	((t_data*)cursor->next->content)->cursor = 1;
	del_lst(cursor);
	get_elems(env);
}

