/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresnel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:19:56 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/22 21:59:49 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_uv		ft_uv(float u, float v)
{
	t_uv	uv;

	uv.u = u;
	uv.v = v;
	return (uv);
}

int			ft_refract(t_vec3 v, t_vec3 n, float ni_over_nt, t_vec3 *r)
{
	t_vec3	uv;
	t_vec3	tmp;
	float	dt;
	float	discr;

	uv = ft_vec3_normalized(v);
	dt = ft_vec3_dot(uv, n);
	discr = 1.0 - ni_over_nt * ni_over_nt * (1.0 - dt * dt);
	if (discr > 0.00001)
	{
		tmp = ft_vec3_kmult(ni_over_nt, ft_vec3_sub(uv,
					ft_vec3_kmult(dt, n)));
		*r = ft_vec3_sub(tmp, ft_vec3_kmult(sqrtf(discr), n));
		return (1);
	}
	else
		return (0);
}
