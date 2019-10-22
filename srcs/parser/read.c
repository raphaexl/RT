/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:57:06 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 16:11:29 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_object		*ft_parse_sphere(t_object *o, char **str)
{
	int		i;

	o->name = "SPHERE";
	o->e.sphere.radius = 1.0;
	i = -1;
	while (str[++i])
	{
		if (ft_rtstrequal("RAD", str[i]) || ft_rtstrequal("RADIUS", str[i]))
			o->e.sphere.radius = ft_float_read(str[i]);
	}
	o->e.sphere.radius2 = o->e.sphere.radius * o->e.sphere.radius;
	o->material = ft_material_read(str);
	return (ft_object_new(SPHERE, o));
}

t_object		*ft_parse_cone(t_object *o, char **str)
{
	int		i;

	o->name = "CONE";
	o->e.cone.angle = 0.5;
	o->e.cone.height = 1.0;
	o->e.cone.v = (t_vec3){0.0, 1.0, 0.0};
	i = -1;
	while (str[++i])
	{
		if (ft_rtstrequal("ANGLE", str[i]) || ft_rtstrequal("THETA", str[i]))
			o->e.cone.angle = DEG_TO_RAD(ft_clamp(1.0, 79.0,
						ft_float_read(str[i])));
		else if (ft_rtstrequal("HEIGHT", str[i]))
			o->e.cone.height = ft_float_read(str[i]);
		else if (ft_rtstrequal("DIRECTION", str[i]) ||
				ft_rtstrequal("DIR", str[i]))
			o->e.cone.v = ft_vec3_normalized(ft_vec3_read(str[i]));
	}
	o->material = ft_material_read(str);
	return (ft_object_new(CONE, o));
}

t_object		*ft_parse_cylinder(t_object *o, char **str)
{
	int		i;

	o->name = "CYLINDER";
	o->e.cylinder.v = (t_vec3){0.0, 1.0, 0.0};
	o->e.cylinder.height = 1.0;
	o->e.cylinder.radius = 0.5;
	i = -1;
	while (str[++i])
	{
		if (ft_rtstrequal("RADIUS", str[i]) || ft_rtstrequal("RAD", str[i]))
			o->e.cylinder.radius = ft_float_read(str[i]);
		else if (ft_rtstrequal("HEIGHT", str[i]))
			o->e.cylinder.height = ft_float_read(str[i]);
		else if (ft_rtstrequal("DIRECTION", str[i]) ||
				ft_rtstrequal("DIR", str[i]))
			o->e.cylinder.v = ft_vec3_normalized(ft_vec3_read(str[i]));
	}
	o->e.cylinder.radius2 = o->e.cylinder.radius * o->e.cylinder.radius;
	o->material = ft_material_read(str);
	return (ft_object_new(CYLINDER, o));
}

t_object		*ft_parse_plane(t_object *o, char **str)
{
	int		i;

	o->name = "PLANE";
	o->e.plane.normal = (t_vec3){0.0, 1.0, 0.0};
	i = -1;
	while (str[++i])
	{
		if (ft_rtstrequal("DIRECTION", str[i]) || ft_rtstrequal("DIR", str[i])
				|| ft_rtstrequal("NORMAL", str[i]) ||
				ft_rtstrequal("NORM", str[i]))
			o->e.plane.normal = ft_vec3_normalized(ft_vec3_read(str[i]));
	}
	o->material = ft_material_read(str);
	return (ft_object_new(PLANE, o));
}

t_object		*ft_parse_ring(t_object *o, char **str)
{
	int		i;

	o->name = "RING";
	o->e.ring.v = (t_vec3){0.0, 1.0, 0.0};
	o->e.ring.height = 1.0;
	o->e.ring.radius = 0.5;
	i = -1;
	while (str[++i])
	{
		if (ft_rtstrequal("RADIUS", str[i]) || ft_rtstrequal("RAD", str[i]))
			o->e.ring.radius = ft_float_read(str[i]);
		else if (ft_rtstrequal("HEIGHT", str[i]))
			o->e.ring.height = ft_float_read(str[i]);
		else if (ft_rtstrequal("DIRECTION", str[i]) || ft_rtstrequal("DIR",
					str[i]))
			o->e.ring.v = ft_vec3_normalized(ft_vec3_read(str[i]));
	}
	o->e.ring.radius2 = o->e.ring.radius * o->e.ring.radius;
	o->material = ft_material_read(str);
	return (ft_object_new(RING, o));
}
