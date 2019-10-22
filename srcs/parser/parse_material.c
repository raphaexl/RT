/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 08:19:48 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 18:00:33 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_mtype		ft_material_type(char *line)
{
	if (ft_rtstrequal("PROCEDURAL", line))
		return (PROCEDURAL);
	else if (ft_rtstrequal("TEXTURE", line))
		return (TEXTURE);
	else if (ft_rtstrequal("PERLIN", line))
		return (PERLIN);
	else if (ft_rtstrequal("MARBLE", line))
		return (MARBLE);
	else if (ft_rtstrequal("TURBULENCE", line))
		return (TURBULENCE);
	else if (ft_rtstrequal("CHESS", line))
		return (CHESS);
	return (NO_PROPERTY);
}

t_texture	*ft_material_texture(char *line)
{
	char		**tab;
	t_texture	*tex;

	if (!(tab = ft_strsplit(line, ' ')) || ft_tab_len(tab) != 3)
		ft_print_error("material invalid texture setting texture : img.bmp!!");
	if (ft_isalpha(*tab[1]))
		tex = ft_texture_new(ft_strlwr(tab[1]));
	else
		tex = ft_texture_new(ft_strlwr(tab[2]));
	return (tex);
}

int			ft_material_componnent(t_material *m, char *line)
{
	if (ft_rtstrequal("DIFFUSE2", line))
		m->diffuse2 = ft_col3_read(line);
	else if (ft_rtstrequal("DIFFUSE", line))
		m->diffuse1 = ft_col3_read(line);
	else if (ft_rtstrequal("SPECULAR", line))
		m->specular = ft_col3_read(line);
	else if (ft_rtstrequal("SHININESS", line))
		m->spec_pow = ft_float_read(line);
	else if (ft_rtstrequal("BUMP", line))
		m->bump = ft_float_read(line);
	else if (ft_rtstrequal("REFLECTION", line))
		m->reflection = ft_float_read(line);
	else if (ft_rtstrequal("REFRACTION", line))
		m->refraction = ft_float_read(line);
	else if (ft_rtstrequal("U_SCALE", line))
		m->u_sc = ft_float_read(line);
	else if (ft_rtstrequal("V_SCALE", line))
		m->v_sc = ft_float_read(line);
	else if (ft_rtstrequal("TYPE", line))
		m->type = ft_material_type(line);
	else if (ft_rtstrequal("TEXTURE", line) && (m->type = TEXTURE))
		m->texture = ft_material_texture(line);
	else
		return (0);
	return (1);
}

int			ft_parse_material(t_material *m, char **str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (ft_material_componnent(m, str[i]))
			;
	return (i);
}

t_material	ft_material_read(char **str)
{
	t_material	m;

	ft_bzero(&m, sizeof(t_material));
	m.u_sc = 1.0;
	m.v_sc = 1.0;
	m.albedo[0] = 1.0;
	m.albedo[1] = 0.2;
	ft_parse_material(&m, str);
	return (m);
}
