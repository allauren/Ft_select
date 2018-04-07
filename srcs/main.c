/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 22:50:40 by allauren          #+#    #+#             */
/*   Updated: 2018/04/07 08:20:40 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_list		*get_elems(t_list **lst)
{
	static t_list **stat = NULL;

	if (lst)
		stat = lst;
	return (*stat);
}

int main(int argc, char *argv[])
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env));
	if (argc < 2 || (!(env.name = getenv("TERM")) || tgetent(NULL, env.name) == -1))
		return (ft_usage());
	if (ft_saveparam(1) == -1 || parseargs(&env, argc, argv) == -1)
		return(ft_print_malloc());
	signals_init();
	get_elems(&env.lst);
	print_all_lst(env.lst);
	del_all_lst(get_elems(NULL));
	char *str;
	while (get_next_line(0, &str));


	return (0);
}
