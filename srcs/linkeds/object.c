/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:54:23 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 15:52:17 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_object	*ft_object_new(t_type type, t_object *o)
{
	t_object	*new;

	if ((new = malloc(sizeof(*new))))
	{
		new->type = type;
		new->pos = o->pos;
		new->id = 0;
		new->emissive = o->emissive;
		new->name = o->name;
		new->translate = o->translate;
		new->rotate = o->rotate;
		new->scale = (t_vec3){1.0f, 1.0f, 1.0f};
		new->e = o->e;
		new->material = o->material;
		new->next = NULL;
	}
	else
		ft_print_error("malloc error");
	return (new);
}

void		ft_object_push_back(t_object **lst, t_object *new)
{
	t_object	*p;
	int			id;

	id = 1;
	if (!lst || !new)
		return ;
	else if (!*lst)
	{
		new->id = 0;
		*lst = new;
	}
	else
	{
		p = *lst;
		while (p->next && ++id)
			p = p->next;
		new->id = id;
		p->next = new;
	}
}

static int	ft_object_add_back1(t_object **lst, t_type type)
{
	if (type == SPHERE)
		ft_object_push_back(lst, ft_sphere_new());
	else if (type == PLANE)
		ft_object_push_back(lst, ft_plane_new());
	else if (type == CONE)
		ft_object_push_back(lst, ft_cone_new());
	else if (type == CYLINDER)
		ft_object_push_back(lst, ft_cylindre_new());
	else if (type == DISK)
		ft_object_push_back(lst, ft_disk_new());
	else if (type == BOX)
		ft_object_push_back(lst, ft_box_new());
	else if (type == TORUS)
		ft_object_push_back(lst, ft_torus_new());
	else if (type == CUBE)
		ft_object_push_back(lst, ft_cube_new());
	else
		return (0);
	return (1);
}

void		ft_object_add_back(t_object **lst, t_type type)
{
	if (ft_object_add_back1(lst, type))
		return ;
	else if (type == TRIANGLE)
		ft_object_push_back(lst, ft_triangle_new());
	else if (type == PARALLELOGRAM)
		ft_object_push_back(lst, ft_parallelogram_new());
	else if (type == RING)
		ft_object_push_back(lst, ft_ring_new());
	else if (type == ELLIPSOID)
		ft_object_push_back(lst, ft_ellipsoid_new());
	else if (type == PARABOLOID)
		ft_object_push_back(lst, ft_paraboloid_new());
	else if (type == MESH)
		ft_object_push_back(lst, ft_mesh_new());
}
