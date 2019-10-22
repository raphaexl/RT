/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readcubemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:14:20 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/21 20:59:37 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void		ft_left_right(t_cubemap *cm, t_col3 *c, t_col3 *out, t_ray r)
{
	if (r.dir.x > 0.0f)
	{
		c = cm->texture + CUBE_RIGHT * cm->w * cm->h;
		*out = ft_read_texture(c,
				ft_uv(1.0f - (r.dir.z / r.dir.x + 1.0f) * 0.5f,
					(r.dir.y / r.dir.x + 1.0f) * 0.5f), cm->w, cm->h);
	}
	else if (r.dir.x < 0.0f)
	{
		c = cm->texture + CUBE_LEFT * cm->w * cm->h;
		*out = ft_read_texture(c,
				ft_uv(1.0f - (r.dir.z / r.dir.x + 1.0f) * 0.5f,
					1.0f - (r.dir.y / r.dir.x + 1.0f) * 0.5f),
				cm->w, cm->h);
	}
}

static void		ft_up_down(t_cubemap *cm, t_col3 *c, t_col3 *out, t_ray r)
{
	if (r.dir.y > 0.0f)
	{
		c = cm->texture + CUBE_UP * cm->w * cm->h;
		*out = ft_read_texture(c,
				ft_uv((r.dir.x / r.dir.y + 1.0f) * 0.5f,
					1.0f - (r.dir.z / r.dir.y + 1.0f) * 0.5f), cm->w, cm->h);
	}
	else if (r.dir.y < 0.0f)
	{
		c = cm->texture + CUBE_DOWN * cm->w * cm->h;
		*out = ft_read_texture(c,
				ft_uv(1.0f - (r.dir.x / r.dir.y + 1.0f) * 0.5f,
					(r.dir.z / r.dir.y + 1.0f) * 0.5f), cm->w, cm->h);
	}
}

static void		ft_fd_backwd(t_cubemap *cm, t_col3 *c, t_col3 *out, t_ray r)
{
	if (r.dir.z > 0.0f)
	{
		c = cm->texture + CUBE_FORWARD * cm->w * cm->h;
		*out = ft_read_texture(c,
				ft_uv((r.dir.x / r.dir.z + 1.0f) * 0.5f,
					(r.dir.y / r.dir.z + 1.0f) * 0.5f), cm->w, cm->h);
	}
	else if (r.dir.z < 0.0f)
	{
		c = cm->texture + CUBE_BACKWARD * cm->w * cm->h;
		*out = ft_read_texture(c,
				ft_uv((r.dir.x / r.dir.z + 1.0f) * 0.5f,
					1.0f - (r.dir.y / r.dir.z + 1) * 0.5f), cm->w, cm->h);
	}
}

static t_col3	ft_cube_map_end(t_cubemap *cm, t_col3 out)
{
	if (cm->srgb)
	{
		out.blue = powf(out.blue, 2.2f);
		out.red = powf(out.red, 2.2f);
		out.green = powf(out.green, 2.2f);
	}
	if (cm->exposed)
	{
		out.blue = -logf(1.0f - out.blue);
		out.red = -logf(1.0f - out.red);
		out.green = -logf(1.0f - out.green);
	}
	return (out);
}

t_col3			ft_read_cubemap(t_cubemap *cm, t_ray r)
{
	t_col3	*c;
	t_col3	out;

	c = NULL;
	out = (t_col3){0.0f, 0.0f, 0.0f};
	if (!cm->texture)
		return (out);
	if ((fabsf(r.dir.x) >= fabsf(r.dir.y)) &&
			(fabsf(r.dir.x) >= fabsf(r.dir.z)))
		ft_left_right(cm, c, &out, r);
	else if ((fabsf(r.dir.y) >= fabsf(r.dir.x)) &&
			(fabsf(r.dir.y) >= fabsf(r.dir.z)))
		ft_up_down(cm, c, &out, r);
	else if ((fabsf(r.dir.z) >= fabsf(r.dir.x)) &&
			(fabsf(r.dir.z) >= fabsf(r.dir.y)))
		ft_fd_backwd(cm, c, &out, r);
	out = ft_cube_map_end(cm, out);
	out.blue /= cm->exposure;
	out.red /= cm->exposure;
	out.green /= cm->exposure;
	return (out);
}
