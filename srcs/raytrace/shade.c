/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:45:32 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/12 14:22:59 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static	void		ft_sphere_get_uv(t_vec3 p, float *u, float *v)
{
	float	phi;
	float	theta;

	phi = atan2(p.y, p.x);
	theta = asin(p.z);
	*u = 1.0 - (phi + M_PI) / (2.0 * M_PI);
	*v = (theta + M_PI / 2.0) / M_PI;
}

static t_col3		ft_procedural_sphere(t_object *o, t_vec3 pos)
{
	int		tx;
	int		ty;
	int		pair;
	t_uv	uv;

	ft_sphere_get_uv(pos, &uv.u, &uv.v);
	uv.u *= o->material.u_sc;
	uv.v *= o->material.v_sc;
	tx = (int)10 * uv.u;
	ty = (int)10 * uv.v;
	pair = (tx & 0x01) == (ty & 0x01);
	if (((10 * uv.u - tx < 0.1) && pair) || (10 * uv.v - ty < 0.1))
		return (o->material.diffuse1);
	return (o->material.diffuse2);
}

static t_col3		ft_procedural_torus(t_object *o, t_vec3 pos)
{
	int		tx;
	int		ty;
	int		pair;
	int		edge;
	t_uv	uv;

	ft_torus_uv(&o->e.torus, ft_vec3(.0, .0, .0), pos, &uv);
	uv.u *= o->material.u_sc;
	uv.v *= o->material.v_sc;
	tx = (int)10 * uv.u;
	ty = (int)10 * uv.v;
	pair = (tx & 0x01) == (ty & 0x01);
	edge = ((10 * uv.u - tx < 0.1) && pair) || (10 * uv.v - ty < 0.1);
	return (edge ? o->material.diffuse1 : o->material.diffuse2);
}

t_col3				ft_procedural_texturing(t_object *o, t_vec3 pos)
{
	t_col3		diffuse;
	float		sines;
	float		amount;

	amount = 10.0;
	if (o->type != SPHERE)
		amount = 1.0;
	diffuse = (t_col3){1.0, 0.0, 0.0};
	if (o->type == TORUS)
		diffuse = ft_procedural_torus(o, pos);
	else if (o->type == SPHERE)
	{
		pos = ft_vec3_kmult(1.0 / o->e.sphere.radius, pos);
		diffuse = ft_procedural_sphere(o, pos);
	}
	else
	{
		sines = sin(amount * pos.x) * sin(amount * pos.y) * sin(amount * pos.z);
		diffuse = (sines < 0.001) ? o->material.diffuse1 : o->material.diffuse2;
	}
	return (diffuse);
}

t_col3				ft_image_texturing(t_object *o, t_vec3 pos)
{
	t_uv		uv;

	uv = (t_uv){.0, .0};
	if (!o->material.texture)
		return ((t_col3){0.2, 0.2, 0.2});
	if (o->type == SPHERE)
	{
		ft_sphere_uv(o, ft_vec3(0., 0., 0.0), pos, &uv);
		return (ft_get_texel(o->material.texture, uv.u, uv.v));
	}
	else if (o->type == CYLINDER)
		ft_cylinder_uv(&o->e.cylinder, ft_vec3(.0, .0, 0.0), pos, &uv);
	else if (o->type == RING)
		ft_ring_uv(&o->e.ring, ft_vec3(.0, .0, 0.0), pos, &uv);
	else if (o->type == PLANE)
	{
		ft_plane_uv(o, o->e.plane.normal, pos, &uv);
		return (ft_get_texel(o->material.texture, uv.u, uv.v));
	}
	else if (o->type == TORUS)
		ft_torus_uv(&o->e.torus, ft_vec3(0.0, 0.0, 0.), pos, &uv);
	else if (o->type == BOX)
		ft_box_uv(&o->e.box, ft_vec3(0.0, 0.0, 0.0), pos, &uv);
	return (ft_texture_image(o->material.texture, uv.u, uv.v));
}
