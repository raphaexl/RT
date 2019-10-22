/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:19:42 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/22 16:30:21 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vec3	ft_normal_bump(t_hit *hit)
{
	t_vec3	noise;
	t_vec3	normal;
	float	bump;
	double	sc;

	sc = 10.0;
	bump = hit->current->material.bump;
	normal = hit->n;
	noise.x = ft_perlin(sc * (double)hit->p.x, sc * (double)hit->p.y,
			sc * (double)hit->p.z);
	noise.y = ft_perlin(sc * (double)hit->p.y, sc * (double)hit->p.z,
			sc * (double)hit->p.x);
	noise.z = ft_perlin(sc * (double)hit->p.z, sc * (double)hit->p.x,
			sc * (double)hit->p.y);
	normal.x = (1.0f - bump) * normal.x + bump * noise.x;
	normal.y = (1.0f - bump) * normal.y + bump * noise.y;
	normal.z = (1.0f - bump) * normal.z + bump * noise.z;
	normal = ft_vec3_normalized(normal);
	return (normal);
}
