/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathtrace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:55:14 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/21 16:44:29 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vec3		ft_random_unit(void)
{
	t_vec3	p;

	p = (t_vec3){1.0, 1.0, 1.0};
	while (p.x * p.x + p.y * p.y + p.z * p.z >= 1.0)
	{
		p = ft_vec3_sub(ft_vec3_kmult(2.0,
					ft_vec3(ft_rand48(), ft_rand48(), ft_rand48())),
				ft_vec3(1.0, 1.0, 1.0));
	}
	return (p);
}

int			ft_lambertian_sc(t_intersect *in, t_col3 *att)
{
	t_vec3	target;

	in->ray.start = in->p;
	target = ft_vec3_sum(ft_vec3_sum(in->p, in->n), ft_random_unit());
	*att = ft_col3_sum(*att, in->current->material.diffuse);
	in->ray.dir = ft_vec3_sub(target, in->p);
	return (1);
}

int			ft_metal_sc(t_intersect *in, t_col3 *att)
{
	t_vec3	reflected;

	in->ray.start = in->p;
	reflected = ft_reflect(ft_vec3_normalized(in->ray.dir), in->n);
	*att = in->current->material.diffuse;
	in->ray.dir = reflected;
	return (ft_vec3_dot(reflected, in->n) > 0);
}

int			ft_dielectric_sc(t_intersect *in, t_col3 *att, float ref_idx)
{
	t_vec3		reflected;
	t_vec3		refracted;
	t_vec3		out_n;
	float		ni_over_nt;

	*att = (t_col3){1.0, 1.0, 1.0};
	in->ray.start = in->p;
	reflected = ft_reflect(in->ray.dir, in->n);
	if ((in->ray.dir.x * in->n.x + in->ray.dir.y * in->n.y +
				in->ray.dir.z * in->n.z) > 0.001)
	{
		out_n = (t_vec3){-in->n.x, -in->n.y, -in->n.z};
		ni_over_nt = ref_idx;
	}
	else
	{
		out_n = (t_vec3){in->n.x, in->n.y, in->n.z};
		ni_over_nt = 1.0 / ref_idx;
	}
	if (ft_refract(in->ray.dir, out_n, ni_over_nt, &refracted))
		in->ray.dir = refracted;
	else
		in->ray.dir = reflected;
	return (1);
}
