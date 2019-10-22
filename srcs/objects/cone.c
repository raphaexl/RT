/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:32:05 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 20:10:49 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_object		*ft_cone_new(void)
{
	t_object	*new;

	if ((new = (t_object *)ft_memalloc(sizeof(*new))))
	{
		new->type = CONE;
		new->name = "CONE";
		new->pos = (t_vec3){0.0, 0.0, 0.0};
		new->translate = (t_vec3){0.0, 0.0, 0.0};
		new->rotate = (t_vec3){0.0, 0.0, 0.0};
		new->scale = (t_vec3){1.0f, 1.0f, 1.0f};
		new->material = ft_default_material();
		new->e.cone.angle = M_PI / 6.0;
		new->e.cone.height = 1.0;
		new->e.cone.v = (t_vec3){0.0, 1.0, 0.0};
		new->next = NULL;
	}
	else
		ft_print_error("malloc error");
	return (new);
}

t_vec3			ft_normal_cone(t_cone *cone, t_vec3 p)
{
	p = ft_vec3_kmult(1.0 / cone->angle, p);
	return (ft_vec3(p.x, 0.001, p.z));
}

int				ft_cone_compute(t_object *p, t_intersect *in)
{
	t_ray	r;

	r = in->ray;
	if (!ft_cone_intersect(&p->e.cone, &r, &in->t))
		return (0);
	in->current = p;
	in->p = ft_vec3_sum(r.start, ft_vec3_kmult(in->t, r.dir));
	in->n = ft_normal_cone(&p->e.cone, in->p);
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
