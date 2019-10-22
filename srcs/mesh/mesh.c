/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:37:56 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/22 12:55:50 by eabdenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_mesh	ft_default_mesh(void)
{
	t_mesh	m;

	m.size = 12;
	m.name = "CUBE";
	if (!(m.triangles = ft_memalloc(sizeof(t_triangle) * m.size)))
		ft_print_error("malloc error");
	m.triangles[0] = (t_triangle){{-1, -1, -1}, {-1, -1, 1}, {-1, 1, 1}};
	m.triangles[1] = (t_triangle){{1, 1, -1}, {-1, -1, -1}, {-1, 1, -1}};
	m.triangles[2] = (t_triangle){{1, -1, 1}, {-1, -1, -1}, {1, -1, -1}};
	m.triangles[3] = (t_triangle){{1, 1, -1}, {1, -1, -1}, {-1, -1, -1}};
	m.triangles[4] = (t_triangle){{-1, -1, -1}, {-1, 1, 1}, {-1, 1, -1}};
	m.triangles[5] = (t_triangle){{1, -1, 1}, {-1, -1, 1}, {-1, -1, -1}};
	m.triangles[6] = (t_triangle){{-1, 1, 1}, {-1, -1, 1}, {1, -1, 1}};
	m.triangles[7] = (t_triangle){{1, 1, 1}, {1, -1, -1}, {1, 1, -1}};
	m.triangles[8] = (t_triangle){{1, -1, -1}, {1, 1, 1}, {1, -1, 1}};
	m.triangles[9] = (t_triangle){{1, 1, 1}, {1, 1, -1}, {-1, 1, -1}};
	m.triangles[10] = (t_triangle){{1, 1, 1}, {-1, 1, -1}, {-1, 1, 1}};
	m.triangles[11] = (t_triangle){{1, 1, 1}, {-1, 1, 1}, {1, -1, 1}};
	return (m);
}

int		ft_mesh_triangulate(t_mesh *m, t_obj *obj)
{
	int		i;
	int		size;

	i = -1;
	if (!(size = obj->vertices.length / 3))
	{
		ft_putendl("WARNING YOUR OBJ HAS NOT BEEN LOADED");
		return (-1);
	}
	if (!(m->triangles = ft_memalloc(sizeof(t_triangle) * size)))
		return (-1);
	while (++i < size)
	{
		m->triangles[i].a = *(t_vec3 *)obj->vertices.items[i * 3 + 0];
		m->triangles[i].b = *(t_vec3 *)obj->vertices.items[i * 3 + 1];
		m->triangles[i].c = *(t_vec3 *)obj->vertices.items[i * 3 + 2];
	}
	m->size = size;
	return (0);
}
