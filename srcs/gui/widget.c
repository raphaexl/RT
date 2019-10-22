/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widget.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:18:36 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/22 13:17:18 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_widget	ft_widget_new(t_ptr *ptr, Uint32 c)
{
	t_widget	w;
	SDL_Surface *surf;

	w.color = c;
	surf = NULL;
	w.ft_mouse_on_widget = &ft_mouse_on_widget;
	w.pos = (SDL_Rect){0, 0, DEFAULT_W, DEFAULT_H};
	if (!(surf = SDL_CreateRGBSurface(0, DEFAULT_W, DEFAULT_H, 32, RMASK,
					GMASK, BMASK, AMASK)))
		ft_print_error("Creating Widget 's Surface");
	if (SDL_FillRect(surf, &w.pos, w.color))
		ft_print_error("Error Colouring the rect surface");
	if (!(w.img = SDL_CreateTextureFromSurface(ptr->renderer, surf)))
		ft_print_error("Creating widget 's Texture");
	SDL_FreeSurface(surf);
	surf = NULL;
	return (w);
}

t_widget	*ft_widget_create(t_ptr *ptr, Uint32 c)
{
	t_widget	*w;
	SDL_Surface	*surf;

	if (!(w = (t_widget *)malloc(sizeof(*w))))
		ft_print_error("Error malloc on creating widget's component !");
	w->color = c;
	w->ft_mouse_on_widget = &ft_mouse_on_widget;
	surf = NULL;
	w->pos = (SDL_Rect){0, 0, DEFAULT_W, DEFAULT_H};
	if (!(surf = SDL_CreateRGBSurface(0, DEFAULT_W, DEFAULT_H, 32,
					RMASK, GMASK, BMASK, AMASK)))
		ft_print_error("Creating Widget 's Surface");
	if (SDL_FillRect(surf, &w->pos, w->color))
		ft_print_error("Error Colouring the rect surface");
	if (!(w->img = SDL_CreateTextureFromSurface(ptr->renderer, surf)))
		ft_print_error("Creating widget 's Texture");
	SDL_FreeSurface(surf);
	surf = NULL;
	return (w);
}

void		ft_widget_clean(t_widget *w)
{
	SDL_DestroyTexture(w->img);
	w->img = NULL;
	free(w);
	w = NULL;
}

void		ft_widget_draw(t_ptr *ptr, t_widget *w, int x, int y)
{
	SDL_Rect	dest;

	dest = (SDL_Rect){x, y, w->pos.w, w->pos.h};
	SDL_RenderCopy(ptr->renderer, w->img, &w->pos, &dest);
}

int			ft_mouse_on_widget(t_widget *w, int x, int y)
{
	if ((x < w->pos.x) || (x > w->pos.x + w->pos.w) ||
			(y < w->pos.y) || (y > w->pos.y + w->pos.h))
		return (0);
	return (1);
}
