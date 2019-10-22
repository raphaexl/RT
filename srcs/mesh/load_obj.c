/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 20:58:28 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/22 12:55:42 by eabdenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void	ft_norm_face(int index[3], t_obj *obj)
{
	if (index[0] > -1)
		ft_vector_push_back(&obj->v_indices, &index[0]);
	if (index[1] > -1)
		ft_vector_push_back(&obj->uv_indices, &index[1]);
	if (index[2] > -1)
		ft_vector_push_back(&obj->n_indices, &index[2]);
}

void		ft_read_face(t_obj *obj, char *tab)
{
	int index[3];
	int	i;

	i = -1;
	memset(index, -1, sizeof(int) * 3);
	index[0] = ft_atoi(tab);
	while (ft_isdigit(tab[++i]))
		;
	if (!tab[i])
		;
	else if (tab[i] && tab[i] == '/' && tab[i + 1] && tab[++i] == '/')
	{
		index[1] = -1;
		index[2] = tab[i + 1] ? ft_atoi(&tab[i + 1]) : -1;
	}
	else
	{
		index[1] = ft_atoi(&tab[i]);
		while (ft_isdigit(tab[++i]))
			;
		if (tab[i] && tab[i] == '/')
			index[2] = ft_atoi(&tab[i + 1]);
	}
	ft_norm_face(index, obj);
}

void		ft_make_obj(t_obj *obj, t_vector *v, t_vector *uvs,
		t_vector *normals)
{
	int		i;
	int		size;

	i = -1;
	size = obj->v_indices.size(&obj->v_indices);
	while (++i < size)
		obj->vertices.push_back(&obj->vertices,
				(t_vec3 *)v->items[*(int *)obj->v_indices.items[i] - 1]);
	size = obj->uv_indices.size(&obj->uv_indices);
	i = -1;
	while (++i < size)
		obj->uvs.push_back(&obj->uvs,
				(t_vec2 *)uvs->items[*(int *)obj->uv_indices.items[i] - 1]);
	size = obj->n_indices.size(&obj->n_indices);
	i = -1;
	while (++i < size)
		obj->normals.push_back(&obj->normals,
				(t_vec3 *)normals->items[*(int *)obj->n_indices.items[i] - 1]);
}
