/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blur.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 22:37:37 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/24 11:21:22 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void	ft_motion_blur_12(double *filter)
{
	filter[12] = 0.555556;
	filter[13] = 0.444444;
	filter[14] = 0.222222;
	filter[15] = 0.055556;
	filter[16] = 0.222222;
	filter[17] = 0.444444;
	filter[18] = 0.444444;
	filter[19] = 0.277778;
	filter[20] = 0;
	filter[21] = 0.055556;
	filter[22] = 0.222222;
	filter[23] = 0.277778;
	filter[24] = 0.222222;
}

void		ft_motion_blur(t_env *env)
{
	double	*filter;

	if (!(filter = ft_memalloc(sizeof(double) * 25)))
		ft_print_error("error malloc");
	filter[0] = 0.222222;
	filter[1] = 0.277778;
	filter[2] = 0.222222;
	filter[3] = 0.055556;
	filter[4] = 0;
	filter[5] = 0.277778;
	filter[6] = 0.444444;
	filter[7] = 0.444444;
	filter[8] = 0.222222;
	filter[9] = 0.055556;
	filter[10] = 0.222222;
	filter[11] = 0.444444;
	ft_motion_blur_12(filter);
	ft_process_filter(env, filter, 5, 7);
	free(filter);
}

void		ft_gauss_blur(t_env *env)
{
	double	*filter;

	if (!(filter = ft_memalloc(sizeof(double) * 9)))
		ft_print_error("error malloc");
	filter[0] = 1;
	filter[1] = 2;
	filter[2] = 1;
	filter[3] = 2;
	filter[4] = 4;
	filter[5] = 2;
	filter[6] = 1;
	filter[7] = 2;
	filter[8] = 1;
	ft_process_filter(env, filter, 3, 16);
	free(filter);
}
