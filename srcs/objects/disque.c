/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disque.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:52:13 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 14:55:15 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_object	*ft_disk_new(void)
{
	t_object	*new;

	if ((new = (t_object *)ft_memalloc(sizeof(*new))))
	{
		new->type = DISK;
		new->name = "DISK";
		new->pos = (t_vec3){0.0, 0.0, 0.0};
		new->translate = (t_vec3){0.0, -1.01, 0.0};
		new->rotate = (t_vec3){0.0, 0.0, 0.0};
		new->scale = (t_vec3){1.0f, 1.0f, 1.0f};
		new->material = ft_default_material();
		new->e.disk.normal = (t_vec3){0.0, 0.0, 1.0};
		new->e.disk.radius = 5.0;
		new->e.disk.radius2 = new->e.disk.radius * new->e.disk.radius;
		new->next = NULL;
	}
	else
		ft_print_error("malloc error");
	return (new);
}

t_vec3		ft_normal_disk(t_disk *disk, int ret)
{
	t_vec3	p;

	if (ret == 1)
		p = disk->normal;
	else
		p = ft_vec3_kmult(-1.0, disk->normal);
	return (p);
}

int			ft_disk_compute(t_object *p, t_intersect *in)
{
	t_ray	r;
	int		ret;

	r = in->ray;
	ret = ft_disk_intersect(&p->e.disk, &r, &in->t);
	if (!ret)
		return (0);
	in->current = p;
	in->p = ft_vec3_sum(r.start, ft_vec3_kmult(in->t, r.dir));
	in->n = ft_normal_disk(&p->e.disk, ret);
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

int			ft_disk_intersect(t_disk *d, t_ray *r, float *t)
{
	float	ddn;
	t_vec3	v;
	t_vec3	dist;
	float	t1;

	ddn = ft_vec3_dot(r->dir, d->normal);
	if (ddn == 0.000001)
		return (0);
	dist = (t_vec3){-r->start.x, -r->start.y, -r->start.z};
	t1 = (ft_vec3_dot(dist, d->normal)) / ddn;
	v = ft_vec3_sum(r->start, ft_vec3_kmult(t1, r->dir));
	if (t1 < *t && t1 > 0.001 && (ft_vec3_dot(v, v) <= d->radius2))
	{
		*t = t1;
		if (ddn > 0)
			return (2);
		return (1);
	}
	return (0);
}
