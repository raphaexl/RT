/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharpen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 22:39:31 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/24 11:21:18 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void		ft_sharpen(t_env *env)
{
	double	*filter;

	if (!(filter = ft_memalloc(sizeof(double) * 9)))
		ft_print_error("error malloc");
	filter[0] = 0;
	filter[1] = -1;
	filter[2] = 0;
	filter[3] = -1;
	filter[4] = 5;
	filter[5] = -1;
	filter[6] = 0;
	filter[7] = -1;
	filter[8] = 0;
	ft_process_filter(env, filter, 3, 1);
	free(filter);
}
