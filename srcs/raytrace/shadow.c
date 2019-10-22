/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:58:49 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/12 20:14:00 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static int	ft_check_shadows1(t_object *p, t_ray r, t_hit *in)
{
	if (p->type == SPHERE && ft_sphere_intersect(&p->e.sphere, &r, &in->t))
		return (1);
	else if (p->type == CONE && ft_cone_intersect(&p->e.cone, &r, &in->t))
		return (1);
	else if (p->type == PLANE && ft_plane_intersect(&p->e.plane, &r,
				&in->t))
		return (1);
	else if (p->type == DISK && ft_disk_intersect(&p->e.disk, &r, &in->t))
		return (1);
	else if (p->type == CYLINDER && ft_cylindre_intersect(&p->e.cylinder, &r,
				&in->t))
		return (1);
	else if (p->type == BOX && ft_box_intersect(&p->e.box, &r, &in->t))
		return (1);
	else if (p->type == CUBE && ft_cube_intersect(&p->e.cube, &r, &in->t))
		return (1);
	else if (p->type == TORUS && ft_torus_intersect(&p->e.torus, &r, &in->t))
		return (1);
	else if (p->type == TRIANGLE && ft_triangle_intersect(&p->e.triangle, &r,
				&in->t))
		return (1);
	else if (p->type == PARALLELOGRAM && ft_parallelogram_intersect(&p->e.para,
				&r, &in->t))
		return (1);
	return (0);
}

int			ft_check_shadows(t_object *p, t_ray r, t_hit *in)
{
	int			i;

	if (ft_check_shadows1(p, r, in))
		return (1);
	else if (p->type == RING && ft_ring_intersect(&p->e.ring, &r, &in->t))
		return (1);
	else if (p->type == PARABOLOID && ft_paraboloid_intersect(&p->e.parab,
				&r, &in->t))
		return (1);
	else if (p->type == ELLIPSOID && ft_ellipsoid_intersect(&p->e.ellipse,
				&r, &in->t))
		return (1);
	else if (p->type == MESH)
	{
		i = -1;
		while (++i < p->e.mesh.size)
			if (ft_mesh_intersect(&p->e.mesh.triangles[i], &r, &in->t))
				return (1);
	}
	return (0);
}
