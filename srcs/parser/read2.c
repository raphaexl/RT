/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 22:29:42 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/12 12:33:25 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_object		*ft_parse_parallelogram(t_object *o, char **str)
{
	int		i;

	o->name = "PARALLELOGRAM";
	o->e.para.a = (t_vec3){-1.0, -1.0, 0.0};
	o->e.para.b = (t_vec3){1.0, -1.0, 0.0};
	o->e.para.c = (t_vec3){1.0, 1.0, 0.0};
	o->e.para.d = (t_vec3){-1.0, 1.0, 0.0};
	i = -1;
	while (str[++i])
	{
		if (ft_rtstrequal("POINTA", str[i]) || ft_rtstrequal("V1", str[i]))
			o->e.para.a = ft_vec3_read(str[i]);
		else if (ft_rtstrequal("POINTB", str[i]) ||
				ft_rtstrequal("V2", str[i]))
			o->e.para.b = ft_vec3_read(str[i]);
		else if (ft_rtstrequal("POINTC", str[i]) ||
				ft_rtstrequal("V3", str[i]))
			o->e.para.c = ft_vec3_read(str[i]);
		else if (ft_rtstrequal("POINTD", str[i]) ||
				ft_rtstrequal("V4", str[i]))
			o->e.para.d = ft_vec3_read(str[i]);
	}
	o->material = ft_material_read(str);
	return (ft_object_new(PARALLELOGRAM, o));
}

t_object		*ft_parse_paraboloid(t_object *o, char **str)
{
	int		i;

	o->name = "PARABOLOID";
	o->e.parab.k = 0.4;
	o->e.parab.v = (t_vec3){0.0, 1.0, 0.0};
	i = -1;
	while (str[++i])
	{
		if (ft_rtstrequal("DIST", str[i]) || ft_rtstrequal("DISTANCE", str[i]))
			o->e.parab.k = ft_float_read(str[i]);
		else if (ft_rtstrequal("DIR", str[i]) ||
				ft_rtstrequal("V", str[i]))
			o->e.parab.v = ft_vec3_read(str[i]);
	}
	o->material = ft_material_read(str);
	return (ft_object_new(PARABOLOID, o));
}

t_object		*ft_parse_ellipsoid(t_object *o, char **str)
{
	int		i;

	o->name = "ELLIPSOID";
	o->e.ellipse.radius = 0.5;
	o->e.ellipse.v = (t_vec3){-1.0, 1.0, 0.0};
	o->e.ellipse.k = 0.4;
	i = -1;
	while (str[++i])
	{
		if (ft_rtstrequal("DIST", str[i]) || ft_rtstrequal("DISTANCE", str[i]))
			o->e.ellipse.k = ft_float_read(str[i]);
		else if (ft_rtstrequal("RADIUS", str[i]) || ft_rtstrequal("V1", str[i]))
			o->e.ellipse.radius = ft_float_read(str[i]);
		else if (ft_rtstrequal("DIR", str[i]) ||
				ft_rtstrequal("V", str[i]))
			o->e.ellipse.v = ft_vec3_read(str[i]);
	}
	o->e.ellipse.radius2 = o->e.ellipse.radius * o->e.ellipse.radius;
	o->material = ft_material_read(str);
	return (ft_object_new(ELLIPSOID, o));
}

t_object		*ft_parse_mesh(t_object *o, char **str)
{
	int		i;

	o->name = "MESH";
	o->pos = ft_vec3(0.0, 0.0, 0.0);
	i = -1;
	o->e.mesh = ft_default_mesh();
	while (str[++i])
	{
		if (ft_rtstrequal("NAME", str[i]) || ft_rtstrequal("FILE", str[i]))
			ft_mesh_load(&o->e.mesh, ft_strlwr(ft_str_read(str[i])));
	}
	o->material = ft_material_read(str);
	return (ft_object_new(MESH, o));
}
