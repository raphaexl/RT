/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:57:20 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/23 12:26:42 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_object		*ft_parse_disk(t_object *o, char **str)
{
	int		i;

	o->name = "DISQUE";
	o->e.disk.normal = (t_vec3){0.0, 1.0, 0.0};
	i = -1;
	while (str[++i])
	{
		if (ft_rtstrequal("RADIUS", str[i]) || ft_rtstrequal("RAD", str[i]))
			o->e.disk.radius = ft_float_read(str[i]);
		else if (ft_rtstrequal("DIRECTION", str[i]) || ft_rtstrequal("DIR",
					str[i]) || ft_rtstrequal("NORMAL", str[i]) ||
				ft_rtstrequal("NORM", str[i]))
			o->e.disk.normal = ft_vec3_normalized(ft_vec3_read(str[i]));
	}
	o->e.disk.radius2 = o->e.disk.radius * o->e.disk.radius;
	o->material = ft_material_read(str);
	return (ft_object_new(DISK, o));
}

t_object		*ft_parse_box(t_object *o, char **str)
{
	int		i;

	o->name = "BOX";
	o->e.box.bounds[0] = ft_vec3(-1.0, -1.0, -1.0);
	o->e.box.bounds[1] = ft_vec3(1.0, 1.0, 1.0);
	i = -1;
	while (str[++i])
	{
		if (ft_rtstrequal("BOUND1", str[i]) || ft_rtstrequal("B1", str[i]) ||
				ft_rtstrequal("AA", str[i]) || ft_rtstrequal("A1", str[i]))
			o->e.box.bounds[0] = ft_vec3_read(str[i]);
		else if (ft_rtstrequal("BOUND2", str[i]) || ft_rtstrequal("B2", str[i])
				|| ft_rtstrequal("BB", str[i]))
			o->e.box.bounds[1] = ft_vec3_read(str[i]);
	}
	o->material = ft_material_read(str);
	return (ft_object_new(BOX, o));
}

t_object		*ft_parse_torus(t_object *o, char **str)
{
	int			i;

	o->name = "TORUS";
	i = -1;
	o->e.torus.radius1 = 1.0;
	o->e.torus.radius2 = 0.2;
	while (str[++i])
	{
		if (ft_rtstrequal("RAD1", str[i]) ||
				ft_rtstrequal("RADIUS1", str[i]))
			o->e.torus.radius1 = ft_float_read(str[i]);
		else if (ft_rtstrequal("RAD2", str[i]) ||
				ft_rtstrequal("RADIUS2", str[i]))
			o->e.torus.radius2 = ft_float_read(str[i]);
		else if (ft_rtstrequal("RAD", str[i]) || ft_rtstrequal("RADIUS",
					str[i]))
			o->e.torus.radius1 = ft_float_read(str[i]);
	}
	o->material = ft_material_read(str);
	return (ft_object_new(TORUS, o));
}

t_object		*ft_parse_cube(t_object *o, char **str)
{
	int		i;

	o->name = "CUBE";
	o->e.cube.radius = 11.8;
	i = -1;
	while (str[++i])
	{
		if (ft_rtstrequal("RAD", str[i]) || ft_rtstrequal("RADIUS", str[i]))
			o->e.cube.radius = ft_float_read(str[i]);
	}
	o->material = ft_material_read(str);
	return (ft_object_new(CUBE, o));
}

t_object		*ft_parse_triangle(t_object *o, char **str)
{
	int		i;

	o->name = "TRIANGLE";
	o->e.triangle.a = (t_vec3){-1.0, -1.0, 0.0};
	o->e.triangle.b = (t_vec3){1.0, -1.0, 0.0};
	o->e.triangle.c = (t_vec3){0.0, 1.0, 0.0};
	i = -1;
	while (str[++i])
	{
		if (ft_rtstrequal("POINTA", str[i]) || ft_rtstrequal("V1", str[i]))
			o->e.triangle.a = ft_vec3_read(str[i]);
		else if (ft_rtstrequal("POINTB", str[i]) || ft_rtstrequal("V2", str[i]))
			o->e.triangle.b = ft_vec3_read(str[i]);
		else if (ft_rtstrequal("POINTC", str[i]) || ft_rtstrequal("V3", str[i]))
			o->e.triangle.c = ft_vec3_read(str[i]);
	}
	o->material = ft_material_read(str);
	return (ft_object_new(TRIANGLE, o));
}
