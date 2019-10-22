/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_uv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:28:17 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/22 00:47:00 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void		ft_plane_uv(t_object *o, t_vec3 n, t_vec3 p, t_uv *uv)
{
	t_vec3			u_axis;
	t_vec3			v_axis;
	t_material		m;

	if (!(m = o->material).texture)
		return ;
	u_axis = ft_vec3(n.y, n.z, -n.x);
	v_axis = ft_vec3_cross(u_axis, n);
	uv->u = ft_vec3_dot(p, u_axis) * m.u_sc;
	uv->v = ft_vec3_dot(p, v_axis) * m.v_sc;
	if (uv->u < 0.0f)
		uv->u *= -1.0f;
	if (uv->v < 0.0f)
		uv->v *= -1.0f;
}
