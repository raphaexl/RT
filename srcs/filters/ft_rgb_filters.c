/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_filters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:45:42 by aabouibr          #+#    #+#             */
/*   Updated: 2019/10/07 21:45:43 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void		ft_grey(t_env *e)
{
	int	i;
	int	j;

	i = -1;
	while (++i < W_W)
	{
		j = -1;
		while (++j < W_H)
			e->pixels[i + j * W_W] = ft_scale_convert_col3(ft_greyscale(
						ft_get_col3(ft_get_color(e->pixels[i + j * W_W]))),
					1).col;
	}
}

void		ft_negative(t_env *e)
{
	int	i;
	int	j;

	i = -1;
	while (++i < W_W)
	{
		j = -1;
		while (++j < W_H)
			e->pixels[i + j * W_W] = ft_scale_convert_col3(ft_negate(
						ft_get_col3(ft_get_color(e->pixels[i + j * W_W]))),
					1).col;
	}
}

void		ft_sepia(t_env *e)
{
	int	i;
	int	j;

	i = -1;
	while (++i < W_W)
	{
		j = -1;
		while (++j < W_H)
			e->pixels[i + j * W_W] = ft_scale_convert_col3(ft_apply_sepia(
						ft_get_col3(ft_get_color(e->pixels[i + j * W_W]))),
					1).col;
	}
}
