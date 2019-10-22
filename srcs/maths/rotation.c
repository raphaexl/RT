/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:57:34 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/21 13:27:34 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vec3	ft_rotate_x(t_vec3 r, float angle)
{
	t_vec3 res;

	res = (t_vec3){0.0, 0.0, 0.0};
	res.x = r.x;
	res.y = r.y * cos(angle) - sin(angle) * r.z;
	res.z = r.y * sin(angle) + cos(angle) * r.z;
	return (res);
}

t_vec3	ft_rotate_y(t_vec3 r, float angle)
{
	t_vec3	res;

	res = (t_vec3){0.0, 0.0, 0.0};
	res.x = r.x * cos(angle) + sin(angle) * r.z;
	res.y = r.y;
	res.z = -r.x * sin(angle) + cos(angle) * r.z;
	return (res);
}

t_vec3	ft_rotate_z(t_vec3 r, float angle)
{
	t_vec3	res;

	res = (t_vec3){0.0, 0.0, 0.0};
	res.x = r.x * cos(angle) - sin(angle) * r.y;
	res.y = r.x * sin(angle) + cos(angle) * r.y;
	res.z = r.z;
	return (res);
}

t_vec3	ft_rotate_vec3(t_vec3 r, t_vec3 v, int invert)
{
	if (invert)
	{
		r = ft_rotate_z(r, DEG_TO_RAD(-v.z));
		r = ft_rotate_y(r, DEG_TO_RAD(-v.y));
		r = ft_rotate_x(r, DEG_TO_RAD(-v.x));
	}
	else
	{
		r = ft_rotate_x(r, DEG_TO_RAD(v.x));
		r = ft_rotate_y(r, DEG_TO_RAD(v.y));
		r = ft_rotate_z(r, DEG_TO_RAD(v.z));
	}
	return (r);
}
