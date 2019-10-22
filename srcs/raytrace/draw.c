/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:52:26 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/12 12:56:35 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static Uint32	ft_clamp_gama(float red, float green, float blue, float factor)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (unsigned char)fmin(red * factor * 255.0, 255.0);
	g = (unsigned char)fmin(green * factor * 255.0, 255.0);
	b = (unsigned char)fmin(blue * factor * 255.0, 255.0);
	return (b + (g << 8) + (r << 16));
}

t_col3			ft_edit_trace(t_scene *s, t_intersect *in, int depth)
{
	in->t = INFINITY;
	(void)depth;
	if (ft_scene_intersect(s, in))
		return (in->current->material.diffuse1);
	return (s->bg_color);
}

void			ft_render(t_scene *s, Uint32 *pixels)
{
	t_intersect	inter;
	int			y;
	int			x;

	x = -1;
	while (++x < W_W)
	{
		y = -1;
		while (++y < W_H)
		{
			s->a = s->nb_samples;
			s->c = (t_col3){0.0, 0.0, 0.0};
			while (--s->a >= 0)
			{
				inter.ray = ft_camera_ray(&s->cam, x + (float)s->a /
						s->nb_samples, y + (float)s->a / s->nb_samples);
				s->c = ft_col3_sum(s->c, s->ft_rtv1(s, &inter, 0));
			}
			pixels[x + (W_H - 1 - y) * W_W] = ft_clamp_gama(s->c.red,
					s->c.green, s->c.blue, 1.0 / s->nb_samples);
		}
	}
}

static	int		ft_rend(void *ptr)
{
	t_intersect	inter;
	t_env		*g;
	int			y;
	int			x;

	g = (t_env *)ptr;
	x = g->start + W_W / NB_THREADS + 1;
	while (--x >= g->start)
	{
		y = W_H;
		while (--y >= 0)
		{
			g->s.a = g->s.nb_samples;
			g->s.c = (t_col3){0.0, 0.0, 0.0};
			while (--g->s.a >= 0)
			{
				inter.ray = ft_camera_ray(&g->s.cam, x + (float)g->s.a /
						g->s.nb_samples, y + (float)g->s.a / g->s.nb_samples);
				g->s.c = ft_col3_sum(g->s.c, g->s.ft_rtv1(&g->s, &inter, 0));
			}
			g->pixels[x + (W_H - 1 - y) * W_W] = ft_clamp_gama(g->s.c.red,
					g->s.c.green, g->s.c.blue, 1.0 / g->s.nb_samples);
		}
	}
	return (0);
}

void			ft_draw(t_env *e)
{
	int				k;
	t_env			arg[NB_THREADS];
	SDL_Thread		*t[NB_THREADS];

	k = -1;
	while (++k < NB_THREADS)
	{
		arg[k] = *e;
		arg[k].start = k * W_W / NB_THREADS;
		t[k] = SDL_CreateThread(ft_rend, "ft_rend", (void *)&arg[k]);
	}
	k = NB_THREADS;
	while (--k >= 0)
		SDL_WaitThread(t[k], NULL);
}
