/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:17:21 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 14:20:27 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static int	ft_object_selectv1(t_inspector *ins, t_object *o)
{
	if (o->type == RING)
	{
		ins->v3[3].e[0].mes = ft_itoaf(o->e.ring.v.x, 2);
		ins->v3[3].e[1].mes = ft_itoaf(o->e.ring.v.y, 2);
		ins->v3[3].e[2].mes = ft_itoaf(o->e.ring.v.z, 2);
	}
	else if (o->type == CYLINDER)
	{
		ins->v3[3].e[0].mes = ft_itoaf(o->e.cylinder.v.x, 2);
		ins->v3[3].e[1].mes = ft_itoaf(o->e.cylinder.v.y, 2);
		ins->v3[3].e[2].mes = ft_itoaf(o->e.cylinder.v.z, 2);
	}
	else
		return (0);
	return (1);
}

int			ft_object_selectv(t_inspector *ins, t_object *o)
{
	if (ft_object_selectv1(ins, o))
		return (1);
	else if (o->type == ELLIPSOID)
	{
		ins->v3[3].e[0].mes = ft_itoaf(o->e.ellipse.v.x, 2);
		ins->v3[3].e[1].mes = ft_itoaf(o->e.ellipse.v.y, 2);
		ins->v3[3].e[2].mes = ft_itoaf(o->e.ellipse.v.z, 2);
	}
	else if (o->type == PARABOLOID)
	{
		ins->v3[3].e[0].mes = ft_itoaf(o->e.parab.v.x, 2);
		ins->v3[3].e[1].mes = ft_itoaf(o->e.parab.v.y, 2);
		ins->v3[3].e[2].mes = ft_itoaf(o->e.parab.v.z, 2);
	}
	else
		return (0);
	return (1);
}
