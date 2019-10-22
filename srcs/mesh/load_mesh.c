/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:50:20 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/21 22:43:18 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

int		ft_mesh_load(t_mesh *mesh, const char *file_name)
{
	t_obj obj;

	ft_memset(&obj, 0, sizeof(t_obj));
	ft_obj_init(&obj);
	ft_load_obj_file(&obj, file_name);
	ft_mesh_triangulate(mesh, &obj);
	ft_obj_clean(&obj);
	return (1);
}

void	ft_mesh_clean(t_mesh *m)
{
	free(m->triangles);
	m->triangles = NULL;
}
