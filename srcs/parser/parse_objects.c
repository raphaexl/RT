/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 00:59:51 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 16:10:10 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_object	*ft_parse_process_spec_1(t_object *o, char **str, t_otype type)
{
	if (type == SPHERE)
		return (ft_parse_sphere(o, str));
	else if (type == CONE)
		return (ft_parse_cone(o, str));
	else if (type == CYLINDER)
		return (ft_parse_cylinder(o, str));
	else if (type == BOX)
		return (ft_parse_box(o, str));
	else if (type == PLANE)
		return (ft_parse_plane(o, str));
	else if (type == DISK)
		return (ft_parse_disk(o, str));
	else if (type == TORUS)
		return (ft_parse_torus(o, str));
	else if (type == CUBE)
		return (ft_parse_cube(o, str));
	else if (type == TRIANGLE)
		return (ft_parse_triangle(o, str));
	else if (type == PARALLELOGRAM)
		return (ft_parse_parallelogram(o, str));
	else if (type == RING)
		return (ft_parse_ring(o, str));
	else if (type == MESH)
		return (ft_parse_mesh(o, str));
	return (NULL);
}

t_object	*ft_parse_process_spec(t_object *o, char **str, t_otype type)
{
	if (type == PARABOLOID)
		return (ft_parse_paraboloid(o, str));
	else if (type == ELLIPSOID)
		return (ft_parse_ellipsoid(o, str));
	else
		return (ft_parse_process_spec_1(o, str, type));
}

t_object	*ft_parse_process_object(char **str, t_otype type)
{
	int			i;
	t_object	o;

	ft_bzero(&o, sizeof(t_object));
	o.scale = (t_vec3){1.0, 1.0, 1.0};
	i = -1;
	while (str[++i])
	{
		if (ft_rtstrequal("POS", str[i]) || ft_rtstrequal("POSITION", str[i]))
			o.pos = ft_vec3_read(str[i]);
		else if (ft_rtstrequal("TRANS", str[i]) ||
				ft_rtstrequal("TRANSLATION", str[i]))
			o.translate = ft_vec3_read(str[i]);
		else if (ft_rtstrequal("ROT", str[i]) ||
				ft_rtstrequal("ROTATION", str[i]))
			o.rotate = ft_vec3_read(str[i]);
		else if (ft_rtstrequal("EMISSIVE", str[i]) ||
				ft_rtstrequal("EMISSION", str[i]))
			o.emissive = ft_bool_read(str[i]);
	}
	o.translate = ft_translate_vec3(o.translate, o.pos, 0);
	o.pos = (t_vec3){0.0, 0.0, 0.0};
	return (ft_parse_process_spec(&o, str, type));
}

int			ft_parse_process_objects(t_scene *s, char *str)
{
	t_rtsplit		split;
	t_otype			type;

	if ((type = ft_parsing_object(ft_strsub(str, 0, OBJECT_NAME))))
	{
		split = ft_parse_process_split(str, '{', '}', '\n');
		if (!split.tab)
			ft_parsing_error(OBJECT_DESCRIPTION);
		ft_object_push_back(&s->obj, ft_parse_process_object(split.tab, type));
		ft_split_free(&split.tab);
		return (split.max);
	}
	return (0);
}
