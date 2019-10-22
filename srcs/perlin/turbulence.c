/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turbulence.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 20:40:40 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 18:00:00 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_col3		ft_perlin_color(t_hit *hit)
{
	double	noisecoef;
	int		i;
	t_col3	c1;
	t_col3	c2;

	noisecoef = 0;
	i = 1;
	while (i < 5)
	{
		noisecoef += (1.0f / i) * fabs((ft_perlin(i * 10 * hit->p.x,
						i * 10 * hit->p.y,
						i * 10 * hit->p.z)));
		i++;
	}
	c1 = hit->current->material.diffuse1;
	c2 = hit->current->material.diffuse2;
	return (ft_col3_sum(ft_col3_kmult(noisecoef, c1),
				ft_col3_kmult(1.0 - noisecoef, c2)));
}

t_col3		ft_marble_color(t_hit *hit)
{
	double	noisecoef;
	int		i;
	t_col3	c1;
	t_col3	c2;

	noisecoef = 0;
	i = 1;
	while (i < 5)
	{
		noisecoef += (1.0f / i) * fabs((ft_perlin(i * 10 * hit->p.x,
						i * 10 * hit->p.y,
						i * 10 * hit->p.z)));
		i++;
	}
	noisecoef = 0.5f * sin((hit->p.x + hit->p.y) *
			5.0f + noisecoef) + 0.5f;
	c1 = hit->current->material.diffuse1;
	c2 = hit->current->material.diffuse2;
	return (ft_col3_sum(ft_col3_kmult(noisecoef, c1),
				ft_col3_kmult(1.0 - noisecoef, c2)));
}

float		ft_turb(t_vec3 p, int depth)
{
	float	accum;
	t_vec3	temp_p;
	float	weight;
	int		i;

	weight = 1.0;
	i = 0;
	accum = 0.0;
	temp_p = p;
	while (++i < depth)
	{
		accum += weight * ft_perlin(temp_p.x, temp_p.y, temp_p.z);
		weight *= 0.5;
		temp_p = ft_vec3_kmult(2.0, temp_p);
	}
	return (fabs(accum));
}

t_col3		ft_perlin_turbulance1(t_hit *hit)
{
	t_col3	c1;
	t_col3	c2;
	float	t;

	c1 = ft_col3_kmult(0.5, hit->current->material.diffuse1);
	c2 = ft_col3_kmult(0.5, hit->current->material.diffuse2);
	t = 1.0 + sin(0.5 * hit->p.x + 0.2 * hit->p.y + 10.0 * hit->p.z) +
		10.0 * ft_turb(hit->p, 7);
	return (ft_col3_sum(ft_col3_kmult(t, c1), ft_col3_kmult(1.0 - t, c2)));
}

t_col3		ft_perlin_noise(t_hit *hit)
{
	if (hit->current->material.type == PERLIN)
		return (ft_perlin_color(hit));
	else if (hit->current->material.type == MARBLE)
		return (ft_marble_color(hit));
	else if (hit->current->material.type == TURBULENCE)
		return (ft_perlin_turbulance1(hit));
	if (hit->current->material.type == CHESS)
	{
		if (((sin(hit->p.x) > 0 ? 1 : -1) * (sin(hit->p.z) > 0 ? 1 : -1)) > 0)
			return (hit->current->material.diffuse1);
	}
	return (hit->current->material.diffuse2);
}
