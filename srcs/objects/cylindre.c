/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:52:00 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 16:10:17 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_object		*ft_cylindre_new(void)
{
	t_object	*new;

	if ((new = (t_object *)ft_memalloc(sizeof(*new))))
	{
		new->type = CYLINDER;
		new->name = "CYLINDER";
		new->pos = (t_vec3){0.0, 0.0, 0.0};
		new->translate = (t_vec3){0.0, 0.0, 0.0};
		new->rotate = (t_vec3){0.0, 0.0, 0.0};
		new->scale = (t_vec3){1.0f, 1.0f, 1.0f};
		new->material = ft_default_material();
		new->e.cylinder.radius = 1.0;
		new->e.cylinder.radius2 = 1.0;
		new->e.cylinder.height = 1.0;
		new->e.cylinder.v = (t_vec3){0.0, 1.0, 0.0};
		new->next = NULL;
	}
	else
		ft_print_error("malloc error");
	return (new);
}

void			ft_normal_cylindre(t_object *p, t_hit *in, t_ray r, int ret)
{
	float	m;

	m = .0;
	if (ret < 0)
		in->n = ft_vec3_kmult(-1.0, p->e.cylinder.v);
	else if (ret > 1)
		in->n = p->e.cylinder.v;
	else
	{
		m = ft_vec3_dot(r.dir, p->e.cylinder.v) * in->t;
		m += ft_vec3_dot(r.start, p->e.cylinder.v);
		in->n = ft_vec3_sub(in->p, ft_vec3_kmult(m, p->e.cylinder.v));
	}
}

int				ft_cylindre_compute(t_object *p, t_intersect *in)
{
	t_ray	r;
	int		ret;

	r = in->ray;
	if (!(ret = ft_cylindre_intersect(&p->e.cylinder, &r, &in->t)))
		return (0);
	in->current = p;
	in->p = ft_vec3_sum(r.start, ft_vec3_kmult(in->t, r.dir));
	ft_normal_cylindre(p, in, r, ret);
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
