/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illuminate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:26:06 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/21 18:02:46 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static int	ft_default_illumination(t_light *l, t_intersect *in)
{
	t_vec3	dist;

	dist = ft_vec3_sub(l->u.def.pos, in->p);
	if (ft_vec3_dot(in->n, dist) <= 0.0f)
		return (0);
	in->t = sqrt(ft_vec3_dot(dist, dist));
	if (in->t <= 0.0f)
		return (0);
	in->ray_light = (t_ray){in->p, ft_vec3_kmult(1.0 / in->t, dist)};
	return (1);
}

static int	ft_point_illumination(t_light *l, t_intersect *in)
{
	t_vec3		dist;

	dist = ft_vec3_sub(l->u.point.pos, in->p);
	if (ft_vec3_dot(in->n, dist) <= 0.0f)
		return (0);
	in->t = sqrt(ft_vec3_dot(dist, dist));
	if (in->t <= 0.0f)
		return (0);
	in->ray_light = (t_ray){in->p, ft_vec3_kmult(1.0 / in->t, dist)};
	return (1);
}

static int	ft_distant_illumination(t_light *l, t_intersect *in)
{
	t_vec3	po;

	if (ft_vec3_dot(in->n, l->u.direct.dir) <= 0.0f)
		return (0);
	in->t = INFINITY;
	po = ft_vec3_sum(in->p, ft_vec3_kmult(1e-4, in->n));
	in->ray_light = (t_ray){po, l->u.direct.dir};
	return (1);
}

int			ft_illuminate(t_light *l, t_intersect *in)
{
	t_vec3	dist;

	if (l->type == DEFAULT_LIGHT)
		return (ft_default_illumination(l, in));
	else if (l->type == POINT_LIGHT)
		return (ft_point_illumination(l, in));
	else if (l->type == SPOT_LIGHT)
	{
		dist = ft_vec3_sub(l->u.spot.pos, in->p);
		if (ft_vec3_dot(in->n, dist) <= 0.0f)
			return (0);
		in->t = sqrt(ft_vec3_dot(dist, dist));
		if (in->t <= 0.0f)
			return (0);
		in->ray_light = (t_ray){in->p, ft_vec3_kmult(1.0 / in->t, dist)};
	}
	else if (l->type == DISTANT_LIGHT)
		return (ft_distant_illumination(l, in));
	return (1);
}
