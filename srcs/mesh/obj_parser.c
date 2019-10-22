/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:21:45 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/21 22:58:41 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	ft_parse_obj_vector(t_vector *v, char *line)
{
	char		**tab;
	t_vec3		vec;

	vec = (t_vec3){.0, 0.0, 0.0};
	if ((tab = ft_strsplit(line, ' ')) && ft_tab_len(tab) == 4)
	{
		vec.x = ft_atof(tab[1]);
		vec.y = ft_atof(tab[2]);
		vec.z = ft_atof(tab[3]);
	}
	ft_split_free(&tab);
	v->push_back(v, &vec);
}

void	ft_parse_obj_uv(t_vector *v, char *line)
{
	char		**tab;
	t_vec2		vec;

	vec = (t_vec2){.0, 0.0};
	if ((tab = ft_strsplit(line, ' ')) && ft_tab_len(tab) == 3)
	{
		vec.x = ft_atof(tab[1]);
		vec.y = ft_atof(tab[2]);
	}
	ft_split_free(&tab);
	v->push_back(v, &vec);
}

void	ft_parse_obj_normal(t_vector *v, char *line)
{
	char		**tab;
	t_vec3		vec;

	vec = (t_vec3){.0, 0.0, .0};
	if ((tab = ft_strsplit(line, ' ')) && ft_tab_len(tab) == 4)
	{
		vec.x = ft_atof(tab[1]);
		vec.y = ft_atof(tab[2]);
		vec.z = ft_atof(tab[3]);
	}
	ft_split_free(&tab);
	v->push_back(v, &vec);
}

void	ft_parse_obj_faces(t_obj *obj, char *line)
{
	char		**tab1;
	int			i;
	int			len;

	i = -1;
	if ((tab1 = ft_strsplit(line, ' ')) && (len = ft_tab_len(tab1)) > 3)
	{
		if (len > 3)
			while (++i < 3)
				ft_read_face(obj, tab1[i + 1]);
		if (len == 5)
		{
			i = 1;
			while (++i < 4)
				ft_read_face(obj, tab1[i + 1]);
			ft_read_face(obj, tab1[1]);
		}
	}
	else
	{
		ft_printf("An error occured : line --> %s\n", line);
		exit(0);
	}
	ft_split_free(&tab1);
}
