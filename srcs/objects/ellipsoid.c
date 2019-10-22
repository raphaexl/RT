/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 15:54:46 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 14:55:14 by ebatchas         ###   ########.fr       */
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

t_object	*ft_ellipsoid_new(void)
{
	t_object	*new;

	if ((new = (t_object *)ft_memalloc(sizeof(*new))))
	{
		new->type = ELLIPSOID;
		new->name = "ELLPISOID";
		new->pos = (t_vec3){0.0, 0.0, 0.0};
		new->translate = (t_vec3){0.0, 0.0, 0.0};
		new->rotate = (t_vec3){0.0, 0.0, 0.0};
		new->scale = (t_vec3){1.0f, 1.0f, 1.0f};
		new->material = ft_default_material();
		new->e.ellipse.k = 0.5;
		new->e.ellipse.v = (t_vec3){0.0, 1.0, 0.0};
		new->e.ellipse.radius = 1.0;
		new->e.ellipse.radius2 = 1.0;
		new->next = NULL;
	}
	else
		ft_print_error("malloc error");
	return (new);
}

t_vec3		ft_normal_ellipsoid(t_ellipsoid *e, t_vec3 p)
{
	t_vec3	cmid;
	t_vec3	r;

	cmid = ft_vec3_kmult(0.5 * e->k, e->v);
	r = ft_vec3_sub(p, cmid);
	return (ft_vec3_kmult(1.0 / e->radius, p));
}

int			ft_ellipsoid_compute(t_object *p, t_intersect *in)
{
	t_ray		r;

	r = in->ray;
	if (!ft_ellipsoid_intersect(&p->e.ellipse, &r, &in->t))
		return (0);
	in->current = p;
	in->p = ft_vec3_sum(r.start, ft_vec3_kmult(in->t, r.dir));
	in->n = ft_normal_ellipsoid(&p->e.ellipse, in->p);
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

int			ft_ellipsoid_intersect(t_ellipsoid *e, t_ray *r, float *t)
{
	t_vec3	x;
	t_delta	d;
	float	a1;
	float	a2;

	x = r->start;
	e->radius2 = e->radius * e->radius;
	a1 = 2.0 * e->k * ft_vec3_dot(r->dir, e->v);
	a2 = e->radius2 + 2.0 * e->k * ft_vec3_dot(x, e->v) - e->k;
	d.a = 4.0 * e->radius2 * ft_vec3_dot(r->dir, r->dir) - a1 * a1;
	d.b = 2.0 * (4.0 * e->radius2 * ft_vec3_dot(r->dir, x) - a1 * a2);
	d.c = 4.0 * e->radius2 * ft_vec3_dot(x, x) - a2 * a2;
	d.delta = d.b * d.b - 4.0 * d.c * d.a;
	if (d.delta < 0.0001)
		return (0);
	d.delta = sqrt(d.delta);
	return (ft_min_ray((-d.b + d.delta) / (2.0 * d.a),
				(-d.b - d.delta) / (2.0 * d.a), t));
}
