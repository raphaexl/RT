/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 09:42:08 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 16:53:09 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	ft_no_object_select(t_inspector *ins)
{
	int		i;
	int		j;

	i = -1;
	while (++i < N_PROPERTIES)
	{
		j = -1;
		while (++j < 3)
			ins->v3[i].e[j].mes = ft_strdup("0.00");
	}
	i = -1;
	while (++i < N_VIEW1)
		ins->v1[i].e.mes = ft_strdup("0.00");
	i = -1;
	while (++i < N_VIEW4)
	{
		j = -1;
		while (++j < 3)
			ins->v4[i].e[j].mes = ft_strdup("0.00");
	}
}

void	ft_object_select1(t_inspector *ins, t_object *o)
{
	ins->v3[0].e[0].mes = ft_itoaf(o->translate.x, 2);
	ins->v3[0].e[1].mes = ft_itoaf(o->translate.y, 2);
	ins->v3[0].e[2].mes = ft_itoaf(o->translate.z, 2);
	ins->v3[1].e[0].mes = ft_itoaf(o->rotate.x, 2);
	ins->v3[1].e[1].mes = ft_itoaf(o->rotate.y, 2);
	ins->v3[1].e[2].mes = ft_itoaf(o->rotate.z, 2);
	ins->v3[2].e[0].mes = ft_itoaf(o->scale.x, 2);
	ins->v3[2].e[1].mes = ft_itoaf(o->scale.y, 2);
	ins->v3[2].e[2].mes = ft_itoaf(o->scale.z, 2);
	ins->v3[8].e[0].mes = ft_itoaf(o->material.diffuse1.red, 2);
	ins->v3[8].e[1].mes = ft_itoaf(o->material.diffuse1.green, 2);
	ins->v3[8].e[2].mes = ft_itoaf(o->material.diffuse1.blue, 2);
	ins->v3[9].e[0].mes = ft_itoaf(o->material.specular.red, 2);
	ins->v3[9].e[1].mes = ft_itoaf(o->material.specular.green, 2);
	ins->v3[9].e[2].mes = ft_itoaf(o->material.specular.blue, 2);
	ins->v1[4].e.mes = ft_itoaf(o->material.spec_pow, 2);
	ins->v4[0].e[0].mes = ft_itoaf(o->material.albedo[0], 2);
	ins->v4[0].e[1].mes = ft_itoaf(o->material.albedo[1], 2);
	ins->v4[0].e[2].mes = ft_itoaf(o->material.reflection, 2);
	ins->v4[0].e[3].mes = ft_itoaf(o->material.refraction, 2);
}

void	ft_object_select2(t_inspector *ins, t_object *o)
{
	if (o->type == PLANE)
	{
		ins->v3[3].e[0].mes = ft_itoaf(o->e.plane.normal.x, 2);
		ins->v3[3].e[1].mes = ft_itoaf(o->e.plane.normal.y, 2);
		ins->v3[3].e[2].mes = ft_itoaf(o->e.plane.normal.z, 2);
	}
	else if (o->type == DISK)
	{
		ins->v3[3].e[0].mes = ft_itoaf(o->e.disk.normal.x, 2);
		ins->v3[3].e[1].mes = ft_itoaf(o->e.disk.normal.y, 2);
		ins->v3[3].e[2].mes = ft_itoaf(o->e.disk.normal.z, 2);
	}
	else if (o->type == CONE)
	{
		ins->v3[3].e[0].mes = ft_itoaf(o->e.cone.v.x, 2);
		ins->v3[3].e[1].mes = ft_itoaf(o->e.cone.v.y, 2);
		ins->v3[3].e[2].mes = ft_itoaf(o->e.cone.v.z, 2);
	}
	else if (!ft_object_selectv(ins, o))
	{
		ins->v3[3].e[0].mes = ft_strdup("0.00");
		ins->v3[3].e[1].mes = ft_strdup("0.00");
		ins->v3[3].e[2].mes = ft_strdup("0.00");
	}
}

void	ft_object_select3(t_inspector *ins, t_object *o)
{
	if (o->type == SPHERE)
		ins->v1[0].e.mes = ft_itoaf(o->e.sphere.radius, 2);
	else if (o->type == CYLINDER)
		ins->v1[0].e.mes = ft_itoaf(o->e.cylinder.radius, 2);
	else if (o->type == RING)
		ins->v1[0].e.mes = ft_itoaf(o->e.ring.radius, 2);
	else if (o->type == DISK)
		ins->v1[0].e.mes = ft_itoaf(o->e.disk.radius, 2);
	else if (o->type == TORUS)
		ins->v1[0].e.mes = ft_itoaf(o->e.torus.radius1, 2);
	else if (o->type == CUBE)
		ins->v1[0].e.mes = ft_itoaf(o->e.cube.radius, 2);
	else if (o->type == ELLIPSOID)
		ins->v1[0].e.mes = ft_itoaf(o->e.ellipse.radius, 2);
	else
		ins->v1[0].e.mes = ft_strdup("0.00");
}
