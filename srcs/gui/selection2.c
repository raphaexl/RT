/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:04:57 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 16:59:15 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	ft_object_select4(t_inspector *ins, t_object *o)
{
	if (o->type == SPHERE)
		ins->v1[1].e.mes = ft_itoaf(o->e.sphere.radius2, 2);
	else if (o->type == CYLINDER)
		ins->v1[1].e.mes = ft_itoaf(o->e.cylinder.radius2, 2);
	else if (o->type == RING)
		ins->v1[1].e.mes = ft_itoaf(o->e.ring.radius2, 2);
	else if (o->type == DISK)
		ins->v1[1].e.mes = ft_itoaf(o->e.disk.radius2, 2);
	else if (o->type == TORUS)
		ins->v1[1].e.mes = ft_itoaf(o->e.torus.radius2, 2);
	else if (o->type == ELLIPSOID)
		ins->v1[1].e.mes = ft_itoaf(o->e.ellipse.radius2, 2);
	else if (o->type == CUBE)
		ins->v1[1].e.mes = ft_itoaf(o->e.cube.radius, 2);
	else if (o->type == PARABOLOID)
		ins->v1[2].e.mes = ft_itoaf(o->e.parab.k, 2);
	else
		ins->v1[1].e.mes = ft_strdup("0.00");
}

int		ft_object_select34(t_inspector *ins, t_object *o)
{
	if (o->type == BOX)
	{
		ins->v3[4].e[0].mes = ft_itoaf(o->e.box.bounds[0].x, 2);
		ins->v3[4].e[1].mes = ft_itoaf(o->e.box.bounds[0].y, 2);
		ins->v3[4].e[2].mes = ft_itoaf(o->e.box.bounds[0].z, 2);
		ins->v3[5].e[0].mes = ft_itoaf(o->e.box.bounds[1].x, 2);
		ins->v3[5].e[1].mes = ft_itoaf(o->e.box.bounds[1].y, 2);
		ins->v3[5].e[2].mes = ft_itoaf(o->e.box.bounds[1].z, 2);
	}
	else if (o->type == TRIANGLE)
	{
		ins->v3[4].e[0].mes = ft_itoaf(o->e.triangle.a.x, 2);
		ins->v3[4].e[1].mes = ft_itoaf(o->e.triangle.a.y, 2);
		ins->v3[4].e[2].mes = ft_itoaf(o->e.triangle.a.z, 2);
		ins->v3[5].e[0].mes = ft_itoaf(o->e.triangle.b.x, 2);
		ins->v3[5].e[1].mes = ft_itoaf(o->e.triangle.b.y, 2);
		ins->v3[5].e[2].mes = ft_itoaf(o->e.triangle.b.z, 2);
		ins->v3[6].e[0].mes = ft_itoaf(o->e.triangle.c.x, 2);
		ins->v3[6].e[1].mes = ft_itoaf(o->e.triangle.c.y, 2);
		ins->v3[6].e[2].mes = ft_itoaf(o->e.triangle.c.z, 2);
	}
	else
		return (0);
	return (1);
}

int		ft_object_select35(t_inspector *ins, t_object *o)
{
	if (o->type == PARALLELOGRAM)
	{
		ins->v3[4].e[0].mes = ft_itoaf(o->e.para.a.x, 2);
		ins->v3[4].e[1].mes = ft_itoaf(o->e.para.a.y, 2);
		ins->v3[4].e[2].mes = ft_itoaf(o->e.para.a.z, 2);
		ins->v3[5].e[0].mes = ft_itoaf(o->e.para.b.x, 2);
		ins->v3[5].e[1].mes = ft_itoaf(o->e.para.b.y, 2);
		ins->v3[5].e[2].mes = ft_itoaf(o->e.para.b.z, 2);
		ins->v3[6].e[0].mes = ft_itoaf(o->e.para.c.x, 2);
		ins->v3[6].e[1].mes = ft_itoaf(o->e.para.c.y, 2);
		ins->v3[6].e[2].mes = ft_itoaf(o->e.para.c.z, 2);
		ins->v3[7].e[0].mes = ft_itoaf(o->e.para.d.x, 2);
		ins->v3[7].e[1].mes = ft_itoaf(o->e.para.d.y, 2);
		ins->v3[7].e[2].mes = ft_itoaf(o->e.para.d.z, 2);
	}
	else if (o->type == ELLIPSOID)
		ins->v1[2].e.mes = ft_itoaf(o->e.ellipse.k, 2);
	else
		return (0);
	return (1);
}

void	ft_object_select5(t_inspector *ins, t_object *o)
{
	if (o->type == CYLINDER)
		ins->v1[2].e.mes = ft_itoaf(o->e.cylinder.height, 2);
	else if (o->type == RING)
		ins->v1[2].e.mes = ft_itoaf(o->e.ring.height, 2);
	else
		ins->v1[2].e.mes = ft_strdup("0.00");
	if (o->type == CONE)
		ins->v1[3].e.mes = ft_itoaf(o->e.cone.angle, 2);
	else
		ins->v1[3].e.mes = ft_strdup("0.00");
	if (!ft_object_select34(ins, o) && !ft_object_select35(ins, o))
	{
		ins->v3[4].e[0].mes = ft_strdup("0.00");
		ins->v3[4].e[1].mes = ft_strdup("0.00");
		ins->v3[4].e[2].mes = ft_strdup("0.00");
		ins->v3[5].e[0].mes = ft_strdup("0.00");
		ins->v3[5].e[1].mes = ft_strdup("0.00");
		ins->v3[5].e[2].mes = ft_strdup("0.00");
		ins->v3[6].e[0].mes = ft_strdup("0.00");
		ins->v3[6].e[1].mes = ft_strdup("0.00");
		ins->v3[6].e[2].mes = ft_strdup("0.00");
		ins->v3[7].e[0].mes = ft_strdup("0.00");
		ins->v3[7].e[1].mes = ft_strdup("0.00");
		ins->v3[7].e[2].mes = ft_strdup("0.00");
	}
}

void	ft_inspector_object(t_inspector *ins, t_object *o)
{
	if (!o)
		ft_no_object_select(ins);
	else
	{
		ft_object_select1(ins, o);
		ft_object_select2(ins, o);
		ft_object_select3(ins, o);
		ft_object_select4(ins, o);
		ft_object_select5(ins, o);
	}
}
