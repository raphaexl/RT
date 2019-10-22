/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:42:34 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/23 10:37:35 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static int		ft_min_ray(float t1, float t2, float *t)
{
	if (((t1 < t2 || t2 < 0.001) && t1 > 0.1) && (t1 < *t))
	{
		*t = t1;
		return (1);
	}
	else if (((t2 < t1 || t1 < 0.001) && t2 > 0.1) && (t2 < *t))
	{
		*t = t2;
		return (1);
	}
	else
		return (0);
}

t_object		*ft_ring_new(void)
{
	t_object	*new;

	if ((new = (t_object *)ft_memalloc(sizeof(*new))))
	{
		new->type = RING;
		new->name = "RING";
		new->pos = (t_vec3){0.0, 0.0, 0.0};
		new->translate = (t_vec3){0.0, 0.0, 0.0};
		new->rotate = (t_vec3){0.0, 0.0, 0.0};
		new->scale = (t_vec3){1.0f, 1.0f, 1.0f};
		new->material = ft_default_material();
		new->e.ring.radius = 1.0;
		new->e.ring.radius2 = 1.0;
		new->e.ring.height = 1.0;
		new->e.ring.v = (t_vec3){0.0, 1.0, 0.0};
		new->next = NULL;
	}
	else
		ft_print_error("malloc error");
	return (new);
}

t_vec3			ft_normal_ring(t_ring *ring, t_vec3 p)
{
	p = ft_vec3_kmult(1.0 / ring->radius, p);
	return (ft_vec3(p.x, 0.001, p.z));
}

int				ft_ring_compute(t_object *p, t_intersect *in)
{
	t_ray	r;
	float	m;

	r = in->ray;
	if (!ft_ring_intersect(&p->e.ring, &r, &in->t))
		return (0);
	in->current = p;
	in->p = ft_vec3_sum(r.start, ft_vec3_kmult(in->t, r.dir));
	m = ft_vec3_dot(r.dir, p->e.ring.v) * in->t;
	m += ft_vec3_dot(r.start, p->e.ring.v);
	in->n = ft_vec3_sub(in->p, ft_vec3_kmult(m, p->e.ring.v));
	if (p->material.bump)
		in->n = ft_normal_bump(in);
	in->p = ft_translate_vec3(in->p, p->translate, 0);
	in->p = ft_rotate_vec3(in->p, p->rotate, 0);
	in->p = ft_scale_vec3(in->p, p->scale, 0);
	in->n = ft_rotate_vec3(in->n, p->rotate, 0);
	in->n = ft_scale_vec3(in->n, p->scale, -1);
	in->n = ft_vec3_normalized(in->n);
	return (1);
}

int				ft_ring_intersect(t_ring *c, t_ray *r, float *t)
{
	t_aux_cylinder	a;

	a.x = r->start;
	a.d.a = ft_vec3_dot(r->dir, r->dir) - pow(ft_vec3_dot(r->dir, c->v), 2);
	a.d.b = 2.0 * (ft_vec3_dot(r->dir, a.x) - ft_vec3_dot(r->dir,
				c->v) * ft_vec3_dot(a.x, c->v));
	a.d.c = ft_vec3_dot(a.x, a.x) - pow(ft_vec3_dot(a.x, c->v), 2) - c->radius2;
	a.d.delta = a.d.b * a.d.b - 4.0 * a.d.a * a.d.c;
	if (a.d.delta < 0.0)
		return (0);
	a.d.delta = sqrt(a.d.delta);
	a.t0 = (-a.d.b + a.d.delta) / (2.0 * a.d.a);
	a.t1 = (-a.d.b - a.d.delta) / (2.0 * a.d.a);
	if (c->height <= 0)
		return (ft_min_ray(a.t0, a.t1, t));
	a.m0 = ft_vec3_dot(r->dir, c->v) * (a.t0);
	a.m0 += ft_vec3_dot(a.x, c->v);
	a.m1 = ft_vec3_dot(r->dir, c->v) * (a.t1);
	a.m1 += ft_vec3_dot(a.x, c->v);
	if (a.m0 > -c->height && a.m0 < c->height)
		return (ft_min_ray(a.t0, a.t1, t));
	else if (a.m1 > -c->height && a.m1 < c->height)
		return (ft_min_ray(a.t1, a.t0, t));
	return (0);
}
