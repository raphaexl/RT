/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emboss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 22:45:08 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/24 11:21:20 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void		ft_emboss(t_env *env)
{
	double	*filter;

	if (!(filter = ft_memalloc(sizeof(double) * 9)))
		ft_print_error("error malloc");
	filter[0] = -2;
	filter[1] = -1;
	filter[2] = 0;
	filter[3] = -1;
	filter[4] = 1;
	filter[5] = 1;
	filter[6] = 0;
	filter[7] = 1;
	filter[8] = 2;
	ft_process_filter(env, filter, 3, 1);
	free(filter);
}
