/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:50:18 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/21 18:57:48 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_col3		ft_get_texel(t_texture *t, float u, float v)
{
	t_aux_textel	a;
	t_col3			c[4];

	a.fu = (u + 1000.5f) * t->w;
	a.fv = (v + 1000.0f) * t->w;
	a.u1 = ((int)a.fu) % t->w;
	a.v1 = ((int)a.fv) % t->h;
	a.u2 = (a.u1 + 1) % t->w;
	a.v2 = (a.v1 + 1) % t->h;
	a.fracu = a.fu - floorf(a.fu);
	a.fracv = a.fv - floorf(a.fv);
	a.w1 = (1 - a.fracu) * (1 - a.fracv);
	a.w2 = a.fracu * (1 - a.fracv);
	a.w3 = (1 - a.fracu) * a.fracv;
	a.w4 = a.fracu * a.fracv;
	c[0] = t->data[a.u1 + a.v1 * t->w];
	c[1] = t->data[a.u2 + a.v1 * t->w];
	c[2] = t->data[a.u1 + a.v2 * t->w];
	c[3] = t->data[a.u2 + a.v2 * t->w];
	c[0] = ft_col3_kmult(a.w1, c[0]);
	c[1] = ft_col3_kmult(a.w2, c[1]);
	c[2] = ft_col3_kmult(a.w3, c[2]);
	c[3] = ft_col3_kmult(a.w4, c[3]);
	return (ft_col3_sum(ft_col3_sum(ft_col3_sum(c[0], c[1]), c[2]), c[3]));
}

t_col3		ft_texture_image(t_texture *t, float u, float v)
{
	int		i;
	int		j;

	i = u * t->w;
	j = (1.0 - v) * t->h - 0.001;
	if (i < 0)
		i = 0;
	if (j < 0)
		j = 0;
	if (i > t->w - 1)
		i = t->w - 1;
	if (j > t->h - 1)
		j = t->h - 1;
	return (t->data[j * t->w + i]);
}
