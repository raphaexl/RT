/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:59:15 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/23 10:37:49 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static int	ft_min_ray(double s[4], float *t, int n)
{
	double	min;
	int		i;

	i = -1;
	while (++i < n)
	{
		if (s[i] > 0.0001)
		{
			min = s[i];
			break ;
		}
	}
	if (i == n)
		return (0);
	while (++i < n)
	{
		if (s[i] > 0.0001 && s[i] < min)
			min = s[i];
	}
	if (min < *t && min > 0.0001)
	{
		*t = min;
		return (n);
	}
	return (0);
}

t_vec3		ft_normal_torus(t_torus *t, t_vec3 h)
{
	t_vec3	p;
	float	x;
	float	y;
	float	z;

	x = h.x;
	y = h.y;
	z = h.z;
	p.x = 4.0 * x * (x * x + y * y + z * z - t->radius2 * t->radius2
			- t->radius1 * t->radius1);
	p.y = 4.0 * y * (x * x + y * y + z * z - t->radius2 * t->radius2
			- t->radius1 * t->radius1 + 2.0 * t->radius1 * t->radius1);
	p.z = 4.0 * z * (x * x + y * y + z * z - t->radius2 * t->radius2
			- t->radius1 * t->radius1);
	return (ft_vec3_normalized(p));
}

t_object	*ft_torus_new(void)
{
	t_object	*new;

	if ((new = (t_object *)ft_memalloc(sizeof(*new))))
	{
		new->type = TORUS;
		new->name = "TORUS";
		new->pos = (t_vec3){0.0, 0.0, 0.0};
		new->translate = (t_vec3){0.0, 0.0, 0.0};
		new->rotate = (t_vec3){0.0, 0.0, 0.0};
		new->scale = (t_vec3){1.0, 1.0, 1.0};
		new->material = ft_default_material();
		new->e.torus.radius1 = 1.0;
		new->e.torus.radius2 = 0.5;
		new->next = NULL;
	}
	else
		ft_print_error("malloc error");
	return (new);
}

int			ft_torus_compute(t_object *p, t_intersect *in)
{
	t_ray		r;

	r = in->ray;
	if (!ft_torus_intersect(&p->e.torus, &r, &in->t))
		return (0);
	in->current = p;
	in->p = ft_vec3_sum(r.start, ft_vec3_kmult(in->t, r.dir));
	in->n = ft_normal_torus(&p->e.torus, in->p);
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

int			ft_torus_intersect(t_torus *t, t_ray *r, float *min)
{
	t_vec3	dist;
	int		num;
	double	c[5];
	double	s[4];

	c[4] = pow(ft_vec3_dot(r->dir, r->dir), 2);
	dist = r->start;
	c[3] = 4.0 * ft_vec3_dot(r->dir, r->dir) * ft_vec3_dot(dist, r->dir);
	c[2] = 2.0 * ft_vec3_dot(r->dir, r->dir) * (ft_vec3_dot(dist, dist) -
			(t->radius1 * t->radius1 + t->radius2 * t->radius2)) + 4.0 *
		pow(ft_vec3_dot(dist, r->dir), 2) +
		4.0 * t->radius1 * t->radius1 * r->dir.y * r->dir.y;
	c[1] = 4.0 * (ft_vec3_dot(dist, dist) - (t->radius1 * t->radius1 +
				t->radius2 * t->radius2)) * ft_vec3_dot(dist, r->dir) +
		8.0 * (t->radius1 * t->radius1) * dist.y * r->dir.y;
	c[0] = pow(ft_vec3_dot(dist, dist) - (t->radius1 * t->radius1 +
				t->radius2 * t->radius2), 2) - 4.0 * (t->radius1 * t->radius1) *
		(t->radius2 * t->radius2 - dist.y * dist.y);
	num = ft_solve_quartic(c, s);
	if (num == 0)
		return (0);
	else
		return (ft_min_ray(s, min, num));
}
