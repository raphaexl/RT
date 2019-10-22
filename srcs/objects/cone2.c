/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 08:56:17 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 20:41:52 by ebatchas         ###   ########.fr       */
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
	return (0);
}

float			ft_get_cone_limits(float t, t_ray *r, t_vec3 va, t_vec3 v)
{
	t_vec3	q;
	float	m1;
	float	m2;

	if (t < 0)
		return (INFINITY);
	q = ft_vec3_sum(r->start, ft_vec3_kmult(t, r->dir));
	m1 = ft_vec3_dot(va, q);
	m2 = ft_vec3_dot(va, ft_vec3_sub(q, v));
	if (m1 < 0.0 && m2 > 0)
		return (t);
	return (INFINITY);
}

static void		ft_aux_cone_init(t_aux_cone *a, t_cone *c, t_ray *r)
{
	a->anglecos = pow(cos(c->angle), 2.0);
	a->anglesin = pow(sin(c->angle), 2.0);
	a->pa = (t_vec3){0.0, 0.0, 0.0};
	a->va = ft_vec3_normalized(ft_vec3_sub(a->pa, c->v));
	a->x = ft_vec3_sub(r->start, a->pa);
	a->a = ft_vec3_sub(r->dir, ft_vec3_kmult(ft_vec3_dot(r->dir, a->va),
				a->va));
	a->b = ft_vec3_sub(a->x, ft_vec3_kmult(ft_vec3_dot(a->x, a->va), a->va));
	a->d.a = a->anglecos * ft_vec3_dot(a->a, a->a) -
		a->anglesin * ft_vec3_dot(r->dir, a->va) * ft_vec3_dot(r->dir, a->va);
	a->d.b = 2.0 * a->anglecos * ft_vec3_dot(a->a, a->b) -
		2.0 * a->anglesin * ft_vec3_dot(r->dir, a->va) * ft_vec3_dot(a->x,
				a->va);
	a->d.c = a->anglecos * ft_vec3_dot(a->b, a->b) -
		a->anglesin * ft_vec3_dot(a->x, a->va) * ft_vec3_dot(a->x, a->va);
	a->d.delta = a->d.b * a->d.b - 4.0 * a->d.a * a->d.c;
}

int				ft_cone_intersect(t_cone *c, t_ray *r, float *t)
{
	t_aux_cone	a;

	ft_aux_cone_init(&a, c, r);
	if (a.d.delta < 0.00000001)
		return (0);
	a.d.delta = sqrt(a.d.delta);
	if (c->height <= 0)
	{
		return (ft_min_ray((-a.d.b + a.d.delta) / (2.0 * a.d.a),
			(-a.d.b - a.d.delta) / (2.0 * a.d.a), t));
	}
	a.t1 = ft_get_cone_limits((-a.d.b + a.d.delta) / (2.0 * a.d.a),
			r, a.va, c->v);
	a.t2 = ft_get_cone_limits((-a.d.b - a.d.delta) / (2.0 * a.d.a),
			r, a.va, c->v);
	if (!ft_min_ray(a.t1, a.t2, t))
		return (0);
	a.m = ft_vec3_dot(r->dir, c->v) * (*t);
	a.m += ft_vec3_dot(r->start, c->v);
	if (a.m > c->height / 2.0 - 5.0e-1)
		return (2);
	return (1);
}
