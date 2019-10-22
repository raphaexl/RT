/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_uv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:27:58 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/21 19:10:35 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void		ft_sphere_uv(t_object *o, t_vec3 n, t_vec3 vp, t_uv *uv)
{
	t_aux_sphere a;

	(void)n;
	a.vn = (t_vec3){0, 1, 0};
	a.ve = (t_vec3){1, 0, 0};
	a.vc = ft_vec3_cross(a.vn, a.ve);
	vp = ft_vec3_kmult(1.0 / o->e.sphere.radius, vp);
	a.phi = acosf(-ft_vec3_dot(vp, a.vn));
	a.theta = (acosf(ft_vec3_dot(a.ve, vp) / sinf(a.phi))) * (2.0f / M_PI);
	if (ft_vec3_dot(a.vc, vp) >= 0)
		uv->u = (1.0f - a.theta) * (1.0 / o->material.u_sc);
	else
		uv->u = a.theta * (1.0 / o->material.u_sc);
	uv->v = a.phi * (1.0 / o->material.v_sc) * (1.0f / M_PI);
}
