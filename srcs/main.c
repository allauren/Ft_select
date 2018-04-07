/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 22:50:40 by allauren          #+#    #+#             */
/*   Updated: 2018/04/07 13:57:29 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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
	if (ft_saveparam(1) == -1 || parseargs(&env, argc, argv) == -1)
		return(ft_print_malloc());
	get_wsize(&env);
	signals_init();
	print_all_lst(env.lst);
	while (1);

	return (0);
}
