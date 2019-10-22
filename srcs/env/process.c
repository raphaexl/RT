/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:56:02 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 13:21:02 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static int	ft_add_objects(t_env *e, t_menu *menu)
{
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	while (++i < NEW_MESH)
	{
		if (menu->keys[NEW_SPHERE + i])
		{
			if (e->s.ft_rtv1 != ft_edit_trace)
				e->s.ft_rtv1 = ft_edit_trace;
			ft_object_add_back(&e->s.obj, NEW_SPHERE + i);
			ret = 1;
			break ;
		}
	}
	return (ret);
}

int			ft_update_options(t_menu *m, t_input *in, int k)
{
	int		i;
	int		is_inside;

	i = 0;
	is_inside = 0;
	while (++i < NB_OPTIONS)
	{
		if (in->mousex < m->pos[i].x || in->mousex > m->pos[i].x + m->pos[i].w)
			is_inside = 0;
		else if (in->mousey < m->pos[i].y || in->mousey > m->pos[i].y
				+ m->pos[i].h)
			is_inside = 0;
		else
			is_inside = 1;
		if (is_inside)
		{
			m->keys[i] = i * k;
			return (1);
		}
		else
			m->keys[i] = 0;
	}
	return (0);
}

static int	ft_env_update_menu(t_env *e, t_menu *menu)
{
	int		ret;

	ret = ft_add_objects(e, menu);
	if (menu->keys[EDIT_TRACE] && (e->s.ft_rtv1 != ft_edit_trace) && (ret = 1))
		e->s.ft_rtv1 = ft_edit_trace;
	if (menu->keys[RAY_TRACE] && (e->s.ft_rtv1 != ft_ray_trace) && (ret = 1))
		e->s.ft_rtv1 = ft_ray_trace;
	if (menu->keys[S_VIDEO])
		ft_save_rt_video(e);
	if (menu->keys[S_PPM])
		ft_save_ppm_pixels(e->pixels, W_W, W_H);
	if (menu->keys[S_BMP])
		ft_save_bmp_pixels(e->pixels, W_W, W_H);
	if (menu->keys[S_PNG])
		ft_save_png_pixels(e->pixels, W_W, W_H);
	if (menu->keys[S_JPG])
		ft_save_jpg_pixels(e->pixels, W_W, W_H);
	if (e->selected && menu->keys[DELETE] && (ret = 1))
	{
		ft_object_remove(&e->s.obj, e->selected->id);
		e->selected = NULL;
	}
	return (ret);
}

static int	ft_env_update_object(t_env *e)
{
	e->selected->scale.x = ft_clamp(0.5, 100.0, e->selected->scale.x);
	e->selected->scale.y = ft_clamp(0.5, 100.0, e->selected->scale.y);
	e->selected->scale.z = ft_clamp(0.5, 100.0, e->selected->scale.z);
	e->selected->rotate.x = ft_clamp(-180.0, 180.0, e->selected->rotate.x);
	e->selected->rotate.y = ft_clamp(-180.0, 180.0, e->selected->rotate.y);
	e->selected->rotate.z = ft_clamp(-180.0, 180.0, e->selected->rotate.z);
	return (1);
}

int			ft_process_event(t_env *e, t_input *in)
{
	static	int		initialized = 0;

	if (!initialized && (initialized = 1))
		return (1);
	if (ft_prev_update(e, in))
		return (1);
	if (ft_env_update_camera(&e->s.cam, in))
		return (1);
	else if (in->mouse[SDL_BUTTON_RIGHT] && ft_update_options(&e->menu, in, 1))
	{
		if (ft_env_update_menu(e, &e->menu))
			return (1);
		return (e->selected && ft_env_update_object(e));
	}
	else if (in->mouse[SDL_BUTTON_LEFT] && ft_update_options(&e->menu, in, 1))
	{
		if (ft_env_update_menu(e, &e->menu))
			return (1);
		return (e->selected && ft_env_update_object(e));
	}
	ft_update_options(&e->menu, in, 0);
	return (0);
}
