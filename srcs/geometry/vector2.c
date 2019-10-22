/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:00:25 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/21 13:24:54 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

float	ft_vec3_norm(t_vec3 a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

float	ft_vec3_norm2(t_vec3 a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}

float	ft_vec3_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec3	ft_vec3_normalized(t_vec3 a)
{
	t_vec3	res;
	float	k;

	k = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	k = 1.0 / k;
	res.x = a.x * k;
	res.y = a.y * k;
	res.z = a.z * k;
	return (res);
}

t_vec3	ft_reflect(t_vec3 v, t_vec3 n)
{
	t_vec3	tmp;

	tmp = ft_vec3_kmult(2.0 * ft_vec3_dot(v, n), n);
	return (ft_vec3_sub(v, tmp));
}
