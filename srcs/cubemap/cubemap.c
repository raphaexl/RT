/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:29:31 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/21 19:48:59 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void	ft_fill_cube(t_cubemap *cube, int *index, t_texture *s)
{
	int		i;
	int		j;

	j = -1;
	while (++j < s->h)
	{
		i = -1;
		while (++i < s->w)
		{
			cube->texture[*index] = s->data[(s->h - 1 - j) * s->w + i];
			(*index)++;
		}
	}
}

t_cubemap	*ft_cubemap_init(char *m[6], int srgb, int exposed)
{
	t_cubemap		*cube;
	t_texture		*s;
	int				number;
	int				i;

	cube = ft_memalloc(sizeof(t_cubemap));
	cube->exposure = 1.0f;
	cube->srgb = srgb;
	cube->exposed = exposed;
	s = ft_texture_new(m[0]);
	cube->w = s->w;
	cube->h = s->h;
	cube->texture = ft_memalloc(sizeof(t_col3) * 6 * cube->w * cube->h);
	i = CUBE_UP;
	number = i * cube->w * cube->h;
	ft_fill_cube(cube, &number, s);
	free(s);
	while (++i <= CUBE_BACKWARD)
	{
		number = i * cube->w * cube->h;
		s = ft_texture_new(m[i]);
		ft_fill_cube(cube, &number, s);
		free(s);
	}
	return (cube);
}

t_col3		ft_read_texture(t_col3 *tab, t_uv uv, int w, int h)
{
	t_aux_read_texture	a;
	t_col3				c[2];

	uv.u = fabsf(uv.u);
	uv.v = fabsf(uv.v);
	a.umin = (int)w * uv.u;
	a.vmin = (int)h * uv.v;
	a.umax = (int)w * uv.u + 1;
	a.vmax = (int)h * uv.v + 1;
	a.ucoef = fabsf(w * uv.u - a.umin);
	a.vcoef = fabsf(h * uv.v - a.vmin);
	a.umin = MIN(MAX(a.umin, 0), w - 1);
	a.umax = MIN(MAX(a.umax, 0), w - 1);
	a.vmin = MIN(MAX(a.vmin, 0), h - 1);
	a.vmax = MIN(MAX(a.vmax, 0), h - 1);
	c[0] = ft_col3_sum(ft_col3_kmult((1.0f - a.ucoef),
				tab[a.umin + w * a.vmin]),
			ft_col3_kmult(a.ucoef, tab[a.umax + w * a.vmin]));
	c[0] = ft_col3_kmult(1.0f - a.vcoef, c[0]);
	c[1] = ft_col3_sum(ft_col3_kmult((1.0f - a.ucoef), tab[a.umin + w * a.vmax])
			, ft_col3_kmult(a.ucoef, tab[a.umax + w * a.vmax]));
	c[1] = ft_col3_kmult(a.vcoef, c[1]);
	return (ft_col3_sum(c[0], c[1]));
}
