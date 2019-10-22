/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:59:30 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/18 21:36:17 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vec3	ft_scale_vec3(t_vec3 r, t_vec3 v, int invert)
{
	if (invert)
	{
		r.x /= v.x;
		r.y /= v.y;
		r.z /= v.z;
	}
	else
	{
		r.x *= v.x;
		r.y *= v.y;
		r.z *= v.z;
	}
	return (r);
}

t_vec3	ft_translate_vec3(t_vec3 r, t_vec3 v, int invert)
{
	if (invert)
	{
		r.x -= v.x;
		r.y -= v.y;
		r.z -= v.z;
	}
	else
	{
		r.x += v.x;
		r.y += v.y;
		r.z += v.z;
	}
	return (r);
}
