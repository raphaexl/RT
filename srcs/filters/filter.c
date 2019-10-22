/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:14:22 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/24 11:37:55 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void	ft_apply_filter(t_convolution conv)
{
	t_point	p;
	t_col3	auxcol;
	t_pixel	curr_col;

	p.x = -1;
	auxcol = (t_col3){.0, .0, .0};
	while (++p.x < conv.size)
	{
		p.y = -1;
		while (++p.y < conv.size)
		{
			curr_col = ft_get_color(
					conv.img[(conv.pix.x + p.x - conv.size / 2) +
					((conv.pix.y + p.y - conv.size / 2) *
					W_W)]);
			auxcol = ft_add_scale_col3(auxcol, ft_get_col3(curr_col),
					conv.filter[p.x + p.y * conv.size]);
		}
	}
	conv.aux[conv.pix.x + conv.pix.y * W_W] =
		ft_scale_convert_col3(auxcol, (double)1 / conv.den).col;
}

void		ft_process_filter(t_env *env, double *filter, int size,
		int den)
{
	t_convolution	conv;

	conv.size = size;
	conv.den = den;
	conv.filter = filter;
	conv.img = env->pixels;
	conv.aux = ft_memalloc(sizeof(Uint32) * W_W * W_H);
	conv.pix.x = -1 + size / 2;
	while (++conv.pix.x < W_W - size / 2)
	{
		conv.pix.y = -1 + size / 2;
		while (++conv.pix.y < W_H - size / 2)
		{
			ft_apply_filter(conv);
		}
	}
	ft_memcpy(conv.img, conv.aux, sizeof(Uint32) * W_W * W_H);
	free(conv.aux);
}

int			ft_filter(t_env *e)
{
	if (e->s.filter == NO_FILTER)
		return (0);
	if (e->s.filter == GREY)
		ft_grey(e);
	if (e->s.filter == NEGATIVE)
		ft_negative(e);
	if (e->s.filter == SEPIA)
		ft_sepia(e);
	if (e->s.filter == EMBOSS)
		ft_emboss(e);
	if (e->s.filter == SHARPEN)
		ft_sharpen(e);
	if (e->s.filter == SOBEL)
		ft_sobel(e);
	if (e->s.filter == GAUSSIAN_BLUR)
		ft_gauss_blur(e);
	if (e->s.filter == MOTION_BLUR)
		ft_motion_blur(e);
	return (0);
}
