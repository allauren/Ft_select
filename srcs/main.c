/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 22:50:40 by allauren          #+#    #+#             */
/*   Updated: 2018/04/07 01:38:57 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int main(int argc, char *argv[])
{
	t_env	env;

	if (argc < 2)
		return (ft_usage());
	ft_bzero(&env, sizeof(t_env));
	if (parseargs(&env, argc, argv) == -1)
		return(ft_print_malloc());
	print_all_lst(env.lst);
	del_all_lst(env.lst);
	return (0);
}
