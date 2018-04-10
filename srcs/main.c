/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 22:50:40 by allauren          #+#    #+#             */
/*   Updated: 2018/04/10 18:01:26 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	isfinish(t_env *env)
{
	t_node	*cursor;	
	int			pass;

	pass = 1;

	cursor = env->lst;
	while (pass || cursor != env->lst)
	{
	pass = 0;
	if(((t_data*)cursor->content)->select)
		ft_printf("%s ",((t_data*)cursor->content)->name);
	cursor = cursor->next;
	}
}
t_env		*get_elems(t_env *env)
{
	static t_env *stat = NULL;

	if (env)
	{
		stat = env;
	}
		return (stat);
}

int main(int argc, char *argv[])
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env));
	if (argc < 2 || (!(env.name = getenv("TERM")) || tgetent(NULL, env.name) == -1))
		return (ft_usage());
	if (open_tty(&env) == -1)
		return(-1);
	if (initterm() == -1)
		return(ft_usage());
	if (ft_saveparam(1) == -1 || parseargs(&env, argc, argv) == -1)
		return(ft_print_malloc());
	signals_init();
	get_wsize(&env);
	if (ft_saveparam(0) == -1)
		return(ft_printf("error in reinit param shell\n") < 0 - 1);
	if (!env.lst)
		return(ft_printf("no value available"));
	isfinish(&env);
	del_all_lst(env.lst);
	return (0);
}
