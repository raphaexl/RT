/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 09:18:36 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 15:46:14 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static int	ft_min_ray(float t1, float t2, float *t)
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

static int	ft_cylindre_cap(t_ray *r, float *t, t_vec3 pos, t_vec3 n)
{
	float	ddn;
	float	t1;
	t_vec3	dist;

	ddn = ft_vec3_dot(r->dir, n);
	if (ddn == 1.0e-6)
		return (0);
	dist = ft_vec3_sub(pos, r->start);
	t1 = (ft_vec3_dot(dist, n)) / ddn;
	if (t1 < *t && t1 > 1e-6)
	{
		*t = t1;
		if (ddn > 1e-6)
			return (2);
		return (1);
	}
	return (0);
}

static int	ft_aux_cylinder_init(t_aux_cylinder *a, t_cylinder *c, t_ray *r,
		float *t)
{
	a->x = r->start;
	a->d.a = ft_vec3_dot(r->dir, r->dir) - pow(ft_vec3_dot(r->dir, c->v), 2);
	a->d.b = 2.0 * (ft_vec3_dot(r->dir, a->x) -
			ft_vec3_dot(r->dir, c->v) * ft_vec3_dot(a->x, c->v));
	a->d.c = ft_vec3_dot(a->x, a->x) - pow(ft_vec3_dot(a->x, c->v), 2)
		- c->radius2;
	a->d.delta = a->d.b * a->d.b - 4.0 * a->d.a * a->d.c;
	if (a->d.delta < 0.0)
		return (0);
	a->d.delta = sqrt(a->d.delta);
	a->t0 = (-a->d.b + a->d.delta) / (2.0 * a->d.a);
	a->t1 = (-a->d.b - a->d.delta) / (2.0 * a->d.a);
	if (c->height <= 0)
		return (ft_min_ray(a->t0, a->t1, t));
	if (a->t0 > a->t1)
	{
		a->m0 = a->t0;
		a->t0 = a->t1;
		a->t1 = a->m0;
	}
	a->m0 = ft_vec3_dot(r->dir, c->v) * (a->t0);
	a->m0 += ft_vec3_dot(a->x, c->v);
	a->m1 = ft_vec3_dot(r->dir, c->v) * (a->t1);
	a->m1 += ft_vec3_dot(a->x, c->v);
	return (5);
}

static int	ft_cylinder_cap1(t_aux_cylinder *a, t_cylinder *c, t_ray *r,
		float *t)
{
	if (a->m1 < -c->height)
		return (0);
	if (ft_cylindre_cap(r, t, ft_vec3_kmult(-c->height, c->v),
				ft_vec3_kmult(-1, c->v)))
		return (-1);
	return (0);
}

int			ft_cylindre_intersect(t_cylinder *c, t_ray *r, float *t)
{
	t_aux_cylinder	a;
	int				ret;

	if ((ret = ft_aux_cylinder_init(&a, c, r, t)) != 5)
		return (ret);
	if (a.m0 < -c->height)
		return (ft_cylinder_cap1(&a, c, r, t));
	else if (a.m0 >= -c->height && a.m0 <= c->height)
	{
		if (a.t0 < 1e-6 || a.t0 > *t)
			return (0);
		*t = a.t0;
		return (1);
	}
	else if (a.m0 > c->height)
	{
		if (a.m1 > c->height)
			return (0);
		if (ft_cylindre_cap(r, t, ft_vec3_kmult(c->height, c->v), c->v))
			return (2);
	}
	return (0);
}
