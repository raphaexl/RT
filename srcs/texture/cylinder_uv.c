/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_uv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:37:00 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/23 12:48:20 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void		ft_cylinder_uv(t_cylinder *c, t_vec3 n, t_vec3 p, t_uv *uv)
{
	(void)n;
	uv->u = atan2(p.z, p.x) / (2.0 * M_PI);
	uv->v = p.y / c->height;
	if (uv->u < 0.0f)
		uv->u *= -1.0;
	if (uv->v < 0.0f)
		uv->v *= -1.0;
}

void		ft_ring_uv(t_ring *c, t_vec3 n, t_vec3 p, t_uv *uv)
{
	(void)n;
	uv->u = atan2(p.z, p.x) / (2.0 * M_PI);
	uv->v = p.y / c->height;
	if (uv->u < 0.0f)
		uv->u *= -1.0;
	if (uv->v < 0.0f)
		uv->v *= -1.0;
}
