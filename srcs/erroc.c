/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erroc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 00:52:54 by allauren          #+#    #+#             */
/*   Updated: 2018/04/07 01:40:12 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_usage(void)
{
	ft_printf("./ft_select with files, should use the pad to move and other\
			keys you may discover\n");
	return (0);
}

int		ft_print_malloc(void)
{
	ft_printf("Malloc error\n");
	return (0);
}
