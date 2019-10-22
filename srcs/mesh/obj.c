/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:13:24 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/21 22:43:12 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void			ft_obj_init(t_obj *obj)
{
	ft_vector_init(&obj->vertices, sizeof(t_vec3));
	ft_vector_init(&obj->uvs, sizeof(t_vec2));
	ft_vector_init(&obj->normals, sizeof(t_vec3));
	ft_vector_init(&obj->v_indices, sizeof(int));
	ft_vector_init(&obj->uv_indices, sizeof(int));
	ft_vector_init(&obj->n_indices, sizeof(int));
}

void			ft_obj_clean(t_obj *obj)
{
	ft_vector_free(&obj->vertices);
	ft_vector_free(&obj->uvs);
	ft_vector_free(&obj->normals);
	ft_vector_free(&obj->v_indices);
	ft_vector_free(&obj->uv_indices);
	ft_vector_free(&obj->n_indices);
}

static void		ft_aux_obj_init(t_aux_obj *o)
{
	ft_vector_init(&o->v_list, sizeof(t_vec3));
	ft_vector_init(&o->uv_list, sizeof(t_vec2));
	ft_vector_init(&o->n_list, sizeof(t_vec3));
}

static void		ft_aux_obj_clean(t_aux_obj *o)
{
	ft_vector_free(&o->v_list);
	ft_vector_free(&o->uv_list);
	ft_vector_free(&o->n_list);
}

int				ft_load_obj_file(t_obj *obj, const char *file_name)
{
	int			fd;
	char		*line;
	t_aux_obj	o;

	fd = open(file_name, O_RDONLY);
	if (fd < 0 || fd > 4096)
		return (-1);
	ft_aux_obj_init(&o);
	while (ft_get_next_line(fd, &line) && line)
	{
		if (line[0] == 'v' && line[1] == ' ')
			ft_parse_obj_vector(&o.v_list, line);
		else if (line[0] == 'v' && line[1] == 't')
			ft_parse_obj_uv(&o.uv_list, line);
		else if (line[0] == 'v' && line[1] == 'n')
			ft_parse_obj_normal(&o.n_list, line);
		else if (line[0] == 'f' && line[1] == ' ')
			ft_parse_obj_faces(obj, line);
		free(line);
	}
	ft_make_obj(obj, &o.v_list, &o.uv_list, &o.n_list);
	ft_aux_obj_clean(&o);
	close(fd);
	return (0);
}
