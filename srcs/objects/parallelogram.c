/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallelogram.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:17:32 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 17:31:39 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_object	*ft_parallelogram_new(void)
{
	t_object	*new;

	if ((new = (t_object *)ft_memalloc(sizeof(*new))))
	{
		new->type = PARALLELOGRAM;
		new->name = "PARALLELOGRAM";
		new->pos = (t_vec3){0.0, 0.0, 0.0};
		new->translate = (t_vec3){0.0, 0.0, 0.0};
		new->rotate = (t_vec3){0.0, 0.0, 0.0};
		new->scale = (t_vec3){1.0f, 1.0f, 1.0f};
		new->e.para.a = (t_vec3){-1.0, -1.0, 0.0};
		new->e.para.b = (t_vec3){1.0, -1.0, 0.0};
		new->e.para.c = (t_vec3){1.0, 1.0, 0.0};
		new->e.para.d = (t_vec3){-1.0, 1.0, 0.0};
		new->material = ft_default_material();
		new->next = NULL;
	}
	else
		ft_print_error("malloc error");
	return (new);
}

t_vec3		ft_normal_parallelogram(t_parallelogram *pr)
{
	t_vec3	n;

	n = ft_vec3_cross(ft_vec3_sub(pr->c, pr->a), ft_vec3_sub(pr->d, pr->a));
	return (ft_vec3_normalized(n));
}

int			ft_parallelogram_compute(t_object *p, t_intersect *in)
{
	t_ray	r;

	r = in->ray;
	if (!ft_parallelogram_intersect(&p->e.para, &r, &in->t))
		return (0);
	in->current = p;
	in->p = ft_vec3_sum(r.start, ft_vec3_kmult(in->t, r.dir));
	in->n = ft_normal_parallelogram(&p->e.para);
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

static int	ft_aux_parallelogram(t_aux_parallelogram *a, t_parallelogram *pa,
		t_ray *r)
{
	if (a->a < 1.0e-6)
		return (0);
	a->q = ft_vec3_cross(a->t, a->e01);
	a->b = ft_vec3_dot(r->dir, a->q) * a->invdet;
	if (a->b < 1.0e-6)
		return (0);
	if ((a->a + a->b) > 1.0001f)
	{
		a->e23 = ft_vec3_sub(pa->d, pa->c);
		a->e21 = ft_vec3_sub(pa->b, pa->c);
		a->p2 = ft_vec3_cross(r->dir, a->e21);
		a->det2 = ft_vec3_dot(a->e23, a->p2);
		if (fabs(a->det2) < 1.0e-6)
			return (0);
		a->invdet2 = 1.0 / a->det2;
		a->t2 = ft_vec3_sub(r->start, pa->c);
		a->a2 = ft_vec3_dot(a->t2, a->p2) * a->invdet2;
		if (a->a2 < 1.0e-6)
			return (0);
		a->q2 = ft_vec3_cross(a->t2, a->e23);
		a->b2 = ft_vec3_dot(r->dir, a->q2) * a->invdet2;
		if (a->b2 < 1.0e-6)
			return (0);
	}
	return (1);
}

int			ft_parallelogram_intersect(t_parallelogram *pa, t_ray *r,
		float *min)
{
	t_aux_parallelogram	a;

	a.e01 = ft_vec3_sub(pa->b, pa->a);
	a.e03 = ft_vec3_sub(pa->d, pa->a);
	a.p = ft_vec3_cross(r->dir, a.e03);
	a.det = ft_vec3_dot(a.e01, a.p);
	if (fabs(a.det) >= 1.0e-6)
	{
		a.invdet = 1.0 / a.det;
		a.t = ft_vec3_sub(r->start, pa->a);
		a.a = ft_vec3_dot(a.t, a.p) * a.invdet;
		if (!ft_aux_parallelogram(&a, pa, r))
			return (0);
		a.t1 = ft_vec3_dot(a.e03, a.q) * a.invdet;
		if (a.t1 < *min && a.t1 > 1.0e-6)
		{
			*min = a.t1;
			return (1);
		}
	}
	return (0);
}
