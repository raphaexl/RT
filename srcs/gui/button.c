/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:22:36 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/23 12:12:42 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_button	ft_button_new(t_ptr *ptr, Uint32 c, Uint32 c2, const char *m)
{
	t_button	w;
	SDL_Surface	*surf;

	w.color = c;
	w.color2 = c2;
	w.ft_mouse_on_button = &ft_mouse_on_button;
	w.pos[0] = (SDL_Rect){0, 0, DEFAULT_W1, DEFAULT_H};
	w.pos[1] = (SDL_Rect){0, 0, DEFAULT_W1, DEFAULT_H};
	if (!(surf = SDL_CreateRGBSurface(0, DEFAULT_W1, DEFAULT_H, 32, RMASK,
					GMASK, BMASK, AMASK)))
		ft_print_error("Creating button 's Surface");
	if (SDL_FillRect(surf, &w.pos[0], w.color))
		ft_print_error("Error Coloruring the rect surface");
	if (!(w.img = SDL_CreateTextureFromSurface(ptr->renderer, surf)))
		ft_print_error("Creating button 's Texture");
	w.tex = ft_get_render_text(ptr->renderer, ft_font(m, DEFAULT_FONT,
				DEFAULT_FSIZE),
			ft_sdl_color(c2));
	if (SDL_QueryTexture(w.tex, NULL, NULL, &w.pos[1].w, &w.pos[1].h))
		ft_print_error("Error SDL_QueryTexture :");
	SDL_FreeSurface(surf);
	surf = NULL;
	return (w);
}

t_button	*ft_button_create(t_ptr *ptr, Uint32 c, Uint32 c2, const char *m)
{
	t_button	*w;
	SDL_Surface	*surf;

	if (!(w = (t_button *)malloc(sizeof(*w))))
		ft_print_error("Error malloc on creating button's component !");
	w->color = c;
	w->color2 = c2;
	w->ft_mouse_on_button = &ft_mouse_on_button;
	w->pos[0] = (SDL_Rect){0, 0, DEFAULT_W1, DEFAULT_H};
	w->pos[1] = (SDL_Rect){0, 0, DEFAULT_W1, DEFAULT_H};
	if (!(surf = SDL_CreateRGBSurface(0, DEFAULT_W1, DEFAULT_H, 32, RMASK,
					GMASK, BMASK, AMASK)))
		ft_print_error("Creating button 's Surface");
	if (SDL_FillRect(surf, &w->pos[0], w->color))
		ft_print_error("Error Coloruring the rect surface");
	if (!(w->img = SDL_CreateTextureFromSurface(ptr->renderer, surf)))
		ft_print_error("Creating button 's Texture");
	if (!(w->tex = ft_get_render_text(ptr->renderer, ft_font(m, DEFAULT_FONT,
						DEFAULT_FSIZE),
					ft_sdl_color(c2))))
		ft_print_error("Error button text rendering ");
	if (SDL_QueryTexture(w->tex, NULL, NULL, &w->pos[1].w, &w->pos[1].h))
		ft_print_error("Error SDL_QueryTexture :");
	SDL_FreeSurface(surf);
	return (w);
}

void		ft_button_clean(t_button *b)
{
	if (b->img)
		SDL_DestroyTexture(b->img);
	if (b->tex)
		SDL_DestroyTexture(b->tex);
}

void		ft_button_draw(t_ptr *ptr, t_button *w, int x, int y)
{
	SDL_Rect	dest;

	dest = (SDL_Rect){x, y, w->pos[0].w, w->pos[0].h};
	SDL_RenderCopy(ptr->renderer, w->img, &w->pos[0], &dest);
	dest = (SDL_Rect){x + w->pos[0].w / 2 - w->pos[1].w / 2,
		y + w->pos[0].h / 2 - w->pos[1].h / 2, w->pos[1].w, w->pos[1].h};
	SDL_RenderCopy(ptr->renderer, w->tex, &w->pos[1], &dest);
}

int			ft_mouse_on_button(t_button *w, int x, int y)
{
	if ((x < w->pos[0].x) || (x > w->pos[0].x + w->pos[0].w) ||
			(y < w->pos[0].y) || (y > w->pos[0].y + w->pos[0].h))
		return (0);
	return (1);
}
