/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:00:17 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/21 19:54:58 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vec3.h"

t_vec3	ft_vec3(float x, float y, float z)
{
	t_vec3 res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

t_vec3	ft_vec3_sum(t_vec3 a, t_vec3 b)
{
	t_vec3 res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_vec3	ft_vec3_sub(t_vec3 a, t_vec3 b)
{
	t_vec3 res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_vec3	ft_vec3_kmult(float k, t_vec3 a)
{
	t_vec3 res;

	res.x = k * a.x;
	res.y = k * a.y;
	res.z = k * a.z;
	return (res);
}

t_vec3	ft_vec3_cross(t_vec3 a, t_vec3 b)
{
	t_vec3 res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return (res);
}
