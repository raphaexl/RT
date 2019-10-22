/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:58:46 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/23 10:36:41 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_object	*ft_sphere_new(void)
{
	t_object	*new;

	if ((new = (t_object *)ft_memalloc(sizeof(*new))))
	{
		new->type = SPHERE;
		new->name = "SPHERE";
		new->pos = (t_vec3){0.0, 0.0, 0.0};
		new->translate = (t_vec3){0.0, 0.0, 0.0};
		new->rotate = (t_vec3){0.0, 0.0, 0.0};
		new->scale = (t_vec3){1.0f, 1.0f, 1.0f};
		new->material = ft_default_material();
		new->e.sphere.radius = 1.0;
		new->e.sphere.radius2 = 1.0;
		new->next = NULL;
	}
	else
		ft_print_error("malloc error");
	return (new);
}

t_vec3		ft_normal_sphere(t_sphere *s, t_vec3 p)
{
	return (ft_vec3_kmult(1.0 / s->radius, p));
}

int			ft_sphere_compute(t_object *p, t_intersect *in)
{
	t_ray		r;

	r = in->ray;
	if (!ft_sphere_intersect(&p->e.sphere, &r, &in->t))
		return (0);
	in->current = p;
	in->p = ft_vec3_sum(r.start, ft_vec3_kmult(in->t, r.dir));
	in->n = ft_normal_sphere(&p->e.sphere, in->p);
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

int			ft_sphere_intersect(t_sphere *s, t_ray *r, float *t)
{
	t_vec3	dist;
	t_delta	d;
	float	t1;
	float	t2;

	d.a = ft_vec3_dot(r->dir, r->dir);
	dist = (t_vec3){-r->start.x, -r->start.y, -r->start.z};
	d.b = 2.0 * ft_vec3_dot(r->dir, dist);
	d.c = ft_vec3_dot(dist, dist) - (s->radius2);
	d.delta = d.b * d.b - 4.0 * d.c * d.a;
	if (d.delta < 0.0001)
		return (0);
	d.delta = sqrt(d.delta);
	t1 = (d.b + d.delta) / (2.0 * d.a);
	t2 = (d.b - d.delta) / (2.0 * d.a);
	if (t1 > t2)
		t1 = t2;
	if ((t1 > 0.001) && (t1 < *t))
	{
		*t = t1;
		return (1);
	}
	return (0);
}
