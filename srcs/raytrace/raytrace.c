/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:56:51 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/12 20:09:17 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static int		ft_reflect_light(t_intersect *in)
{
	t_vec3	reflect;

	reflect = ft_reflect(in->ray.dir, in->n);
	in->ray.start = ft_vec3_sum(in->p, ft_vec3_kmult(0.001, reflect));
	in->ray.dir = ft_vec3_normalized(reflect);
	return (1);
}

static void		ft_texture_object(t_hit *hit, t_object *o, t_material *m,
		t_vec3 pos)
{
	if (m->type == NO_PROPERTY)
	{
		m->diffuse = m->diffuse1;
		return ;
	}
	pos = ft_scale_vec3(pos, o->scale, -1);
	pos = ft_rotate_vec3(pos, o->rotate, -1);
	pos = ft_translate_vec3(pos, o->translate, -1);
	if ((m)->type == PROCEDURAL)
		m->diffuse = ft_procedural_texturing(o, pos);
	else if (m->type == TEXTURE)
		m->diffuse = ft_image_texturing(o, pos);
	else if (m->type > TEXTURE)
		m->diffuse = ft_perlin_noise(hit);
}

static t_col3	ft_light(t_scene *s, t_intersect *in, t_material m, t_col3 c)
{
	t_light		*p;

	p = s->light;
	ft_texture_object(in, in->current, &m, in->p);
	c = ft_col3_sum(c, ft_ambient_light(&m.diffuse, &s->ambiant));
	if (in->current->emissive)
		return (ft_col3_sum(c, m.diffuse));
	while (p)
	{
		if (!ft_illuminate(p, in))
		{
			p = p->next;
			continue;
		}
		if (!ft_scene_intersectl(s, in))
			c = ft_col3_sum(c, ft_trace(in, &m, p));
		p = p->next;
	}
	return (c);
}

t_col3			ft_ray_trace(t_scene *s, t_intersect *in, int depth)
{
	t_col3		c;

	c = (t_col3){0.0, 0.0, 0.0};
	in->t = INFINITY;
	if (!ft_scene_intersect(s, in))
		return (s->ft_bg_color(s, in, 0));
	if (depth >= MAX_DEPTH)
		return (c);
	c = ft_col3_sum(c, ft_light(s, in, in->current->material, c));
	if ((in->current->material.reflection > 1.0) && ft_metal_sc(in, &c))
		c = ft_col3_mult(c, ft_ray_trace(s, in, depth + 1));
	else if (in->current->material.refraction > 0.0)
	{
		if (ft_dielectric_sc(in, &c, in->current->material.refraction))
			c = ft_col3_mult(c, ft_ray_trace(s, in, depth + 1));
	}
	else if (in->current->material.reflection > 0.0)
	{
		ft_reflect_light(in);
		c = ft_col3_sum(c, ft_col3_kmult(in->current->material.reflection,
					ft_ray_trace(s, in, depth + 1)));
	}
	return (c);
}
