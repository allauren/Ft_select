/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 00:56:09 by allauren          #+#    #+#             */
/*   Updated: 2018/04/10 17:34:18 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		deldata(t_data *data)
{
	ft_strdel(&data->name);
}

void		del_lst(t_node *lst)
{
	t_data *lol;

	lol = (t_data*)lst->content;
	deldata(lol);
	ft_memdel((void**)&lst->content);
	ft_memdel((void**)&lst);
}

void		del_all_lst(t_node *lst)
{
	t_data *data;

	if (lst)
	{
		data = lst->content;
		if (!((t_data*)(lst->next->content))->start)
			del_all_lst(lst->next);
		del_lst(lst);
	}
}


void		print_all_lst(t_node *lst)
{
	t_data *data;

	if (lst)
	{
			set_caps("ue");
			set_caps("se");
		data = lst->content;
		if (data->cursor)
		{
			set_caps("us");
		}
		if (data->select)
			set_caps("so");
		ft_putendl_fd(data->name, get_elems(NULL)->fd);
		if (!((t_data*)(lst->next->content))->start)
			print_all_lst(lst->next);
	}
}
