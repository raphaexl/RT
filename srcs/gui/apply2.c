/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 12:33:51 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 17:01:51 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	ft_object_apply6(t_inspector *ins, t_object **o)
{
	if ((*o)->type == BOX)
	{
		(*o)->e.box.bounds[0].x = ft_atof(ins->v3[4].e[0].mes);
		(*o)->e.box.bounds[0].y = ft_atof(ins->v3[4].e[1].mes);
		(*o)->e.box.bounds[0].z = ft_atof(ins->v3[4].e[2].mes);
		(*o)->e.box.bounds[1].x = ft_atof(ins->v3[5].e[0].mes);
		(*o)->e.box.bounds[1].y = ft_atof(ins->v3[5].e[1].mes);
		(*o)->e.box.bounds[1].z = ft_atof(ins->v3[5].e[2].mes);
	}
	else if ((*o)->type == TRIANGLE)
	{
		(*o)->e.triangle.a.x = ft_atof(ins->v3[4].e[0].mes);
		(*o)->e.triangle.a.y = ft_atof(ins->v3[4].e[1].mes);
		(*o)->e.triangle.a.z = ft_atof(ins->v3[4].e[2].mes);
		(*o)->e.triangle.b.x = ft_atof(ins->v3[5].e[0].mes);
		(*o)->e.triangle.b.y = ft_atof(ins->v3[5].e[1].mes);
		(*o)->e.triangle.b.z = ft_atof(ins->v3[5].e[2].mes);
		(*o)->e.triangle.c.x = ft_atof(ins->v3[6].e[0].mes);
		(*o)->e.triangle.c.y = ft_atof(ins->v3[6].e[1].mes);
		(*o)->e.triangle.c.z = ft_atof(ins->v3[6].e[2].mes);
	}
}

void	ft_object_apply7(t_inspector *ins, t_object **o)
{
	if ((*o)->type == PARALLELOGRAM)
	{
		(*o)->e.para.a.x = ft_atof(ins->v3[4].e[0].mes);
		(*o)->e.para.a.y = ft_atof(ins->v3[4].e[1].mes);
		(*o)->e.para.a.z = ft_atof(ins->v3[4].e[2].mes);
		(*o)->e.para.b.x = ft_atof(ins->v3[5].e[0].mes);
		(*o)->e.para.b.y = ft_atof(ins->v3[5].e[1].mes);
		(*o)->e.para.b.z = ft_atof(ins->v3[5].e[2].mes);
		(*o)->e.para.c.x = ft_atof(ins->v3[6].e[0].mes);
		(*o)->e.para.c.y = ft_atof(ins->v3[6].e[1].mes);
		(*o)->e.para.c.z = ft_atof(ins->v3[6].e[2].mes);
		(*o)->e.para.d.x = ft_atof(ins->v3[7].e[0].mes);
		(*o)->e.para.d.y = ft_atof(ins->v3[7].e[1].mes);
		(*o)->e.para.d.z = ft_atof(ins->v3[7].e[2].mes);
	}
}

void	ft_object_apply8(t_inspector *ins, t_object **o)
{
	if ((*o)->type == CYLINDER)
		(*o)->e.cylinder.height = ft_atof(ins->v1[2].e.mes);
	else if ((*o)->type == RING)
		(*o)->e.ring.height = ft_atof(ins->v1[2].e.mes);
	else if ((*o)->type == CONE)
		(*o)->e.cone.height = ft_atof(ins->v1[2].e.mes);
	else if ((*o)->type == ELLIPSOID)
		(*o)->e.ellipse.k = ft_atof(ins->v1[2].e.mes);
	else if ((*o)->type == PARABOLOID)
		(*o)->e.parab.k = ft_atof(ins->v1[2].e.mes);
	if ((*o)->type == CONE)
		(*o)->e.cone.angle = ft_atof(ins->v1[3].e.mes);
}

void	ft_inspector_apply(t_inspector *ins, t_object **o)
{
	if (!*o)
		return ;
	else
	{
		ft_object_apply1(ins, o);
		ft_object_apply2(ins, o);
		ft_object_apply3(ins, o);
		ft_object_apply4(ins, o);
		ft_object_apply5(ins, o);
		ft_object_apply6(ins, o);
		ft_object_apply7(ins, o);
		ft_object_apply8(ins, o);
	}
}
