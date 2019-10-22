/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:50:13 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 14:55:20 by ebatchas         ###   ########.fr       */
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

t_object	*ft_box_new(void)
{
	t_object	*new;

	if ((new = (t_object *)ft_memalloc(sizeof(*new))))
	{
		new->type = BOX;
		new->name = "BOX";
		new->e.box.bounds[0] = (t_vec3){-1.0, -1.0, -1.0};
		new->translate = (t_vec3){0.0, 0.0, 0.0};
		new->rotate = (t_vec3){0.0, 0.0, 0.0};
		new->scale = (t_vec3){1.0f, 1.0f, 1.0f};
		new->e.box.bounds[1] = (t_vec3){1.0, 1.0, 1.0};
		new->material = ft_default_material();
		new->next = NULL;
	}
	else
		ft_print_error("malloc error");
	return (new);
}

t_vec3		ft_normal_box(t_box *b, t_vec3 h)
{
	t_vec3	c;
	t_vec3	d;
	t_vec3	p;
	float	bias;

	bias = 1.00001;
	c = ft_vec3_kmult(0.5, ft_vec3_sum(b->bounds[0], b->bounds[1]));
	d = ft_vec3_kmult(0.5, ft_vec3_sub(b->bounds[0], b->bounds[1]));
	d.x = fabs(d.x) * bias;
	d.y = fabs(d.y) * bias;
	d.z = fabs(d.z) * bias;
	p = ft_vec3_sub(h, c);
	return (ft_vec3_normalized(ft_vec3(p.x / d.x, p.y / d.y, p.z / d.z)));
}

int			ft_box_compute(t_object *p, t_intersect *in)
{
	t_ray	r;

	r = in->ray;
	if (!ft_box_intersect(&p->e.box, &r, &in->t))
		return (0);
	in->current = p;
	in->p = ft_vec3_sum(r.start, ft_vec3_kmult(in->t, r.dir));
	in->n = ft_normal_box(&p->e.box, in->p);
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

int			ft_box_intersect(t_box *b, t_ray *r, float *min)
{
	t_vec3		t[3];
	int			sign[3];
	t_vec3		bounds[2];

	bounds[0] = b->bounds[0];
	bounds[1] = b->bounds[1];
	t[2] = (t_vec3){1.0 / r->dir.x, 1.0 / r->dir.y, 1.0 / r->dir.z};
	sign[0] = t[2].x < 0.00001;
	sign[1] = t[2].y < 0.00001;
	sign[2] = t[2].z < 0.00001;
	t[0].x = (bounds[sign[0]].x - r->start.x) * t[2].x;
	t[1].x = (bounds[1 - sign[0]].x - r->start.x) * t[2].x;
	t[0].y = (bounds[sign[1]].y - r->start.y) * t[2].y;
	t[1].y = (bounds[1 - sign[1]].y - r->start.y) * t[2].y;
	if ((t[0].x > t[1].y) || (t[0].y > t[1].x))
		return (0);
	t[0].x = (t[0].y > t[0].x) ? t[0].y : t[0].x;
	t[1].x = (t[1].y < t[1].x) ? t[1].y : t[1].x;
	t[0].z = (bounds[sign[2]].z - r->start.z) * t[2].z;
	t[1].z = (bounds[1 - sign[2]].z - r->start.z) * t[2].z;
	if ((t[0].x > t[1].z) || (t[0].z > t[1].x))
		return (0);
	t[0].x = (t[0].z > t[0].x) ? t[0].z : t[0].x;
	t[1].x = (t[1].z < t[1].x) ? t[1].z : t[1].x;
	return (ft_min_ray(t[0].x, t[1].x, min));
}
